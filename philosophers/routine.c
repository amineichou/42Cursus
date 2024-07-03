/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:05:05 by moichou           #+#    #+#             */
/*   Updated: 2024/07/03 14:32:50 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_routine(t_philosopher *philo)
{
	// take forks
	pthread_mutex_lock(&(philo->fst_fork->lock));
	safe_print_r(philo->info, philo->id, "has taken a fork");
	pthread_mutex_lock(&(philo->sec_fork->lock));
	safe_print_r(philo->info, philo->id, "has taken a fork");
	// start eating
	safe_print_r(philo->info, philo->id, "is eating");
	ft_usleep(philo->info->time_to_eat);
	set_val(&(philo->last_meal_lock), &(philo->last_meal), ft_get_time());
	// let go forks
	pthread_mutex_unlock(&(philo->fst_fork->lock));
	pthread_mutex_unlock(&(philo->sec_fork->lock));
}

void	sleep_routine(t_philosopher *philo)
{
	ft_usleep(philo->info->time_to_sleep);
	safe_print_r(philo->info, philo->id, "is sleeping");
}

void	think_routine(t_philosopher *philo)
{
	safe_print_r(philo->info, philo->id, "is thinking");
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	set_val(&(philo->last_meal_lock), &(philo->last_meal), ft_get_time());
	while (get_val_b(&(philo->info->philo_died_lock), &(philo->info->philo_died)) == false)
	{
		eat_routine(philo);
		sleep_routine(philo);
		think_routine(philo);
	}
	return (NULL);
}
