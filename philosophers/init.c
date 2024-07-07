/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:51:07 by moichou           #+#    #+#             */
/*   Updated: 2024/07/07 12:11:10 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_philosopher *head)
{
	t_philosopher	*tmp;

	tmp = head;
	if (tmp->info->philo_total == 1)
	{
		pthread_create(&tmp->id_thread, NULL, routine, tmp);
		pthread_detach(tmp->id_thread);
		return ;
	}
	while (tmp)
	{
		pthread_create(&tmp->id_thread, NULL, routine, tmp);
		tmp = tmp->next;
	}
}

void	end_simulation(t_philosopher *head)
{
	t_philosopher	*tmp;

	tmp = head;
	while (tmp)
	{
		pthread_join(tmp->id_thread, NULL);
		tmp = tmp->next;
	}
}

t_philosopher	*init(t_philoinfo *info)
{
	t_philosopher	*head;
	t_fork			*forks;

	forks = create_forks(info);
	if (!forks)
		return (NULL);
	info->forks = forks;
	head = create_philos(info, forks);
	if (!head)
		return (NULL);
	return (head);
}
