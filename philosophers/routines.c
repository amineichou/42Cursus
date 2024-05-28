/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:57:12 by moichou           #+#    #+#             */
/*   Updated: 2024/05/28 22:47:19 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philosopher *philo)
{
	printf("%d %d doth eat....\n", philo->info->timestamp.tv_usec, philo->id);
	usleep(philo->info->time_to_eat);
}

static void	ft_sleep(t_philosopher *philo)
{
	printf("%d %d doth sleeping...\n", philo->info->timestamp.tv_usec, philo->id);
	usleep(philo->info->time_to_sleep);
}

static void	ft_think(t_philosopher *philo)
{
	printf("%d %d thinketh...\n", philo->info->timestamp.tv_usec, philo->id);
}

void	ft_monitor(t_philosopher *philo)
{
	if (philo->info->time_to_die == 0 || philo->info->number_of_times_each_philosopher_must_eat == 0)
	{
		printf("%d hath shuffled off this mortal coil\n", philo->id);
		exit(0);
	}
}

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
		(philo->info->time_to_die)--;
		ft_monitor(philo);
	}
	return (NULL);
}
