/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:48:49 by moichou           #+#    #+#             */
/*   Updated: 2024/06/30 16:24:36 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_val(pthread_mutex_t *mtx, long value)
{
	long	new;
	pthread_mutex_lock(mtx);
	new = value;
	pthread_mutex_unlock(mtx);
	return (new);
}

void	ft_set_val(pthread_mutex_t *mtx, long *value, long new)
{
	pthread_mutex_lock(mtx);
	*value = new;
	pthread_mutex_unlock(mtx);
}

bool	ft_get_val_b(pthread_mutex_t *mtx, bool value)
{
	bool	new;
	pthread_mutex_lock(mtx);
	new = value;
	pthread_mutex_unlock(mtx);
	return (new);
}

void	ft_set_val_b(pthread_mutex_t *mtx, bool *value, bool new)
{
	pthread_mutex_lock(mtx);
	*value = new;
	pthread_mutex_unlock(mtx);
}
