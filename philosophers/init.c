/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:51:07 by moichou           #+#    #+#             */
/*   Updated: 2024/07/03 15:36:08 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher	*init(t_philoinfo *info)
{
	t_philosopher	*head;
	t_fork			*forks;

	// create forks
	forks = create_forks(info);
	// create philosphers
	head = create_philos(info, forks);
	if (!head)
		return (NULL);
	return (head);
}
