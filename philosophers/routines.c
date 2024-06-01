/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:57:12 by moichou           #+#    #+#             */
/*   Updated: 2024/06/01 22:00:17 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philosopher *philo)
{
	(void)philo;
	printf("%d %d is eating....\n", philo->info->timestamp.tv_usec, philo->id);
	usleep(philo->info->time_to_eat);
}

static void	ft_sleep(t_philosopher *philo)
{
	(void)philo;
	printf("%d %d is sleeping...\n", philo->info->timestamp.tv_usec, philo->id);
	usleep(philo->info->time_to_sleep);
}

static void	ft_think(t_philosopher *philo)
{
	(void)philo;
	printf("%d %d is thinking...\n", philo->info->timestamp.tv_usec, philo->id);
}
// static void	ft_start_routine(t_routine routine, t_philosopher *philo)
// {
// 	if (routine == EAT)
// 		ft_safe_print(EAT, philo);
// 	else if (routine == SLEEP)
// 		ft_safe_print(SLEEP, philo);
// 	else if (routine == THINK)
// 		ft_safe_print(THINK, philo);
// }

void	*ft_monitor(void *arg)
{
	t_philosopher	*philo_lst;

	philo_lst = (t_philosopher *)arg;
	while (philo_lst)
	{
		pthread_mutex_lock(philo_lst->rotine);
		if (philo_lst->info->time_to_die == 0)
			(printf("%d %d died\n", philo_lst->info->timestamp.tv_usec, philo_lst->id), exit(0));
		pthread_mutex_unlock(philo_lst->rotine);
		philo_lst = philo_lst->next;
		if (philo_lst->id == 1)
			break ;
	}
	return (NULL);
}

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (philo->info->time_to_die)
	{
		pthread_mutex_lock(philo->lock_print);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
		pthread_mutex_unlock(philo->lock_print);
	}
	return (NULL);
}
