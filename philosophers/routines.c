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

char *ft_get_routine(t_routine routine)
{
	if (routine == 0)
		return ("eating");
	else if (routine == 1)
		return ("sleeping");
	else if (routine == 2)
		return ("thinking");
	return ("nothing");
}

long long	ft_get_time(void)
{
	struct timeval	timestamp;
	gettimeofday(&timestamp, NULL);
	return ((long long)timestamp.tv_sec * 1000 + (long long)timestamp.tv_usec / 1000);
}

void	ft_take_fork(t_philosopher *philo)
{
	t_fork	*closest;

	closest = philo->forks;
	while (closest->id != philo->id)
		closest = closest->next;
	pthread_mutex_lock(&closest->lock);
	printf("%lld %d has taken a fork\n", ft_get_time(), philo->id);
	// take the second fork
	if (closest->next)
	{
		pthread_mutex_lock(&closest->next->lock);
		printf("%lld %d has taken a fork\n", ft_get_time(), philo->id);
	}
	else
	{
		pthread_mutex_lock(&philo->forks->lock);
		printf("%lld %d has taken a fork\n", ft_get_time(), philo->id);
	}
}

void ft_let_fork(t_philosopher *philo)
{
	t_fork	*closest;

	closest = philo->forks;
	while (closest->id != philo->id)
		closest = closest->next;
	pthread_mutex_unlock(&closest->lock);
	// let the second fork
	if (closest->next)
	{
		pthread_mutex_unlock(&closest->next->lock);
		printf("%lld %d has taken a fork\n", ft_get_time(), philo->id);
	}
	else
	{
		pthread_mutex_unlock(&philo->forks->lock);
		printf("%lld %d has taken a fork\n", ft_get_time(), philo->id);
	}
}

void ft_safe_print(t_routine routine, t_philosopher *philo)
{
	if (routine == EAT)
		ft_take_fork(philo);
	pthread_mutex_lock(philo->lock_print);
	printf("%lld %d is %s...\n", ft_get_time(), philo->id, ft_get_routine(routine));
	if (routine == SLEEP)
		usleep(philo->info->time_to_sleep);
	pthread_mutex_unlock(philo->lock_print);
	if (routine == EAT)
		ft_let_fork(philo);
}

static void	ft_start_routine(t_routine routine, t_philosopher *philo)
{
	if (routine == EAT)
		ft_safe_print(EAT, philo);
	else if (routine == SLEEP)
		ft_safe_print(SLEEP, philo);
	else if (routine == THINK)
		ft_safe_print(THINK, philo);
}

void	*ft_monitor(void *arg)
{
	t_philosopher	*philo_lst;

	philo_lst = (t_philosopher *)arg;
	while (philo_lst)
	{
		pthread_mutex_lock(philo_lst->rotine);
		if (philo_lst->info->time_to_die == 0)
			(printf("%lld %d died\n", ft_get_time(), philo_lst->id), exit(0));
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
		ft_start_routine(0, philo);
		ft_start_routine(1, philo);
		ft_start_routine(2, philo);
	}
	return (NULL);
}
