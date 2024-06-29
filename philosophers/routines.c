/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:57:12 by moichou           #+#    #+#             */
/*   Updated: 2024/06/03 20:09:50 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->fst_fork->lock);
	ft_safe_print(philo, "has taken a fork", -1);
	pthread_mutex_lock(&philo->sec_fork->lock);
	ft_safe_print(philo, "has taken a fork", -1);
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->last_meal_lock);
	pthread_mutex_unlock(&philo->fst_fork->lock);
	pthread_mutex_unlock(&philo->sec_fork->lock);
}

static void	ft_start_routine(t_routine routine, t_philosopher *philo)
{
	if (routine == EAT)
		ft_eat(philo);
	else if (routine == SLEEP)
	{
		ft_safe_print(philo, "is", SLEEP);
		ft_usleep(philo->info->time_to_sleep);
	}
	else if (routine == THINK)
	{
		ft_safe_print(philo, "is", THINK);
	}
}

void	*ft_monitor(void *arg)
{
	t_philosopher	*philo_lst;
	t_philosopher	*head;
	long 			test;

	philo_lst = (t_philosopher *)arg;
	head = philo_lst;
	while (true)
	{
		pthread_mutex_lock(&philo_lst->last_meal_lock);
		test = ft_get_time() - philo_lst->last_meal;
		pthread_mutex_unlock(&philo_lst->last_meal_lock);
		int id = philo_lst->id;
		if (test > philo_lst->info->time_to_die)
		{
			ft_safe_print(philo_lst, "died", -1);
			exit(0);
		}
		if (philo_lst->next == NULL)
			philo_lst = head;
		else
			philo_lst = philo_lst->next;
	}
	return (NULL);
}

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		ft_start_routine(EAT, philo);
		ft_start_routine(SLEEP, philo);
		ft_start_routine(THINK, philo);
	}
	return (NULL);
}
