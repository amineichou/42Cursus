/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:57:12 by moichou           #+#    #+#             */
/*   Updated: 2024/05/27 20:05:10 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philosopher *philo)
{
	printf("%d %d is eating...\n", philo->info->timestamp.tv_usec, philo->id);
	usleep(philo->info->time_to_eat);
}

static void	ft_sleep(t_philosopher *philo)
{
	printf("%d %d is sleeping...\n", philo->info->timestamp.tv_usec, philo->id);
	usleep(philo->info->time_to_sleep);
}

static void	ft_think(t_philosopher *philo)
{
	printf("%d %d is thinking...\n", philo->info->timestamp.tv_usec, philo->id);
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
		if (philo->info->time_to_die == 0)
		{
			printf("Died\n");
			exit(0);
		}
	}
	return (NULL);
}
