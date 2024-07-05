/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:51:07 by moichou           #+#    #+#             */
/*   Updated: 2024/07/05 16:55:21 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*init(t_philoinfo *info)
{
	t_philosopher	*head;
	t_fork			*forks;

	forks = create_forks(info);
	if (!forks)
		return (NULL);
	head = create_philos(info, forks);
	if (!head)
		return (NULL);
	return (head);
}
