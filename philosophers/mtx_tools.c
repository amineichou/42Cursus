/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:33:26 by moichou           #+#    #+#             */
/*   Updated: 2024/07/05 11:35:28 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_val(pthread_mutex_t *mtx, long *value)
{
	long	new;

	pthread_mutex_lock(mtx);
	new = *value;
	pthread_mutex_unlock(mtx);
	return (new);
}

void	set_val(pthread_mutex_t *mtx, long *value, long new)
{
	pthread_mutex_lock(mtx);
	*value = new;
	pthread_mutex_unlock(mtx);
}

bool	get_val_b(pthread_mutex_t *mtx, bool *value)
{
	bool	new;

	pthread_mutex_lock(mtx);
	new = *value;
	pthread_mutex_unlock(mtx);
	return (new);
}

void	set_val_b(pthread_mutex_t *mtx, bool *value, bool new)
{
	pthread_mutex_lock(mtx);
	*value = new;
	pthread_mutex_unlock(mtx);
}
