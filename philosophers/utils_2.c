/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:35:49 by moichou           #+#    #+#             */
/*   Updated: 2024/07/07 12:14:10 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	timestamp;

	gettimeofday(&timestamp, NULL);
	return ((timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000));
}

void	ft_usleep(long time, t_philoinfo *info)
{
	long	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
	{
		if (get_val_b(&info->philo_died_lock, &info->philo_died))
			break ;
		usleep(100);
	}
}

// routine safe print
void	safe_print_r(t_philoinfo *info, int philo_id, char *message)
{
	if (get_val_b(&info->philo_died_lock, &info->philo_died))
		return ;
	pthread_mutex_lock(&info->print_lock);
	if (get_val_b(&info->philo_died_lock, &info->philo_died))
	{
		pthread_mutex_unlock(&info->print_lock);
		return ;
	}
	printf("%ld %d %s\n", ft_get_time() - info->start_time, philo_id, message);
	pthread_mutex_unlock(&info->print_lock);
}

void	free_philos(t_philosopher *philo)
{
	t_philosopher	*tofree;

	while (philo)
	{
		tofree = philo;
		philo = philo->next;
		if (tofree)
		{
			pthread_mutex_destroy(&tofree->last_meal_lock);
			pthread_mutex_destroy(&tofree->eaten_meals_lock);
			free(tofree);
		}
	}
}

void	clean_program(t_philosopher *philo, t_fork *forks)
{
	t_fork			*tofree;

	pthread_mutex_destroy(&philo->info->print_lock);
	pthread_mutex_destroy(&philo->info->philo_died_lock);
	free_philos(philo);
	while (forks)
	{
		tofree = forks;
		if (forks)
			forks = forks->next;
		pthread_mutex_destroy(&tofree->lock);
		free(tofree);
	}
}
