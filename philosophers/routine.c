/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:05:05 by moichou           #+#    #+#             */
/*   Updated: 2024/07/05 21:14:39 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// take forks eat and let forks
void	eat_routine(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->fst_fork->lock);
	safe_print_r(philo->info, philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->sec_fork->lock);
	safe_print_r(philo->info, philo->id, "has taken a fork");
	safe_print_r(philo->info, philo->id, "is eating");
	ft_usleep(philo->info->time_to_eat, philo->info);
	if (philo->info->meals_total != -1)
	{
		pthread_mutex_lock(&philo->eaten_meals_lock);
		philo->eaten_meals++;
		pthread_mutex_unlock(&philo->eaten_meals_lock);
	}
	set_val(&philo->last_meal_lock, &philo->last_meal, ft_get_time());
	pthread_mutex_unlock(&philo->fst_fork->lock);
	pthread_mutex_unlock(&philo->sec_fork->lock);
}

void	sleep_routine(t_philosopher *philo)
{
	safe_print_r(philo->info, philo->id, "is sleeping");
	ft_usleep(philo->info->time_to_sleep, philo->info);
}

void	think_routine(t_philosopher *philo)
{
	safe_print_r(philo->info, philo->id, "is thinking");
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2)
		ft_usleep(100, philo->info);
	while (get_val_b(&philo->info->philo_died_lock,
			&philo->info->philo_died) == false)
	{
		eat_routine(philo);
		sleep_routine(philo);
		think_routine(philo);
	}
	return (NULL);
}
