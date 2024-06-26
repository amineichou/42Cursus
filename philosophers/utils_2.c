/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:35:49 by moichou           #+#    #+#             */
/*   Updated: 2024/07/01 18:43:57 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	timestamp;
	gettimeofday(&timestamp, NULL);
	return ((timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000));
}

void	ft_usleep(long time)
{
	long	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
	{
		usleep(1);
	}
}

// routine safe print
void	safe_print_r(t_philoinfo *info, int philo_id, char *message)
{
	// bool tmp = get_val_b(&(info->philo_died_lock), &(info->philo_died));
	// if (tmp)
	// {
	// 	return ;
	// }
	pthread_mutex_lock(&info->lock_print);
	printf("%ld %d %s\n", ft_get_time() - info->start_time, philo_id, message);
	pthread_mutex_unlock(&info->lock_print);
}
