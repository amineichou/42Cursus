/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:35:13 by moichou           #+#    #+#             */
/*   Updated: 2024/07/01 16:54:33 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	appand_philosopher(t_philosopher **head, t_philosopher *node)
{
	t_philosopher	*tmp;

	tmp = *head;
	if (*head == NULL)
	{
		*head = node;
		node->next = NULL;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
}

t_philosopher	*create_philos(t_philoinfo *info, t_fork *forks)
{
	t_philosopher	*lst;
	t_philosopher	*node;
	int				id;

	lst = NULL;
	id = 1;
	int i = info->philo_total;
	while (i--)
	{
		node = ft_malloc(sizeof(t_philosopher));
		node->id = id;
		node->last_meal = 0;
		node->fst_fork = get_fork(forks, id);
		if (id == info->philo_total)
			node->sec_fork= get_fork(forks, 0);
		else
			node->sec_fork = get_fork(forks, id + 1);
		// if ((id + 1) % 2 == 0)
		// {
		// 	node->fst_fork = get_fork(forks, id);
		// 	node->sec_fork = get_fork(forks, (id + 1) % info->number_of_philosophers);
		// }
		// else
		// {
		// 	node->fst_fork = get_fork(forks, (id + 1) % info->number_of_philosophers);
		// 	node->sec_fork = get_fork(forks, id);
		// }
		node->info = info;
		pthread_mutex_init(&node->last_meal_lock, NULL);
		pthread_mutex_init(&node->info->lock_print, NULL);
		id++;
		appand_philosopher(&lst, node);
	}
	return (lst);
}

static void append_fork(t_fork **lst, t_fork *node)
{
	t_fork	*tmp;

	tmp = *lst;
	if ((*lst) == NULL)
	{
		*lst = node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

t_fork	*create_forks(t_philoinfo *info)
{
	t_fork	*lst;
	t_fork	*node;
	int		id;
	int		philo_num;

	lst = NULL;
	id = 1;
	philo_num = info->philo_total;
	while (philo_num)
	{
		node = ft_malloc(sizeof(t_fork));
		node->id = id;
		node->next = NULL;
		pthread_mutex_init(&node->lock, NULL);
		append_fork(&lst, node);
		id++;
		philo_num--;
	}
	return (lst);
}

t_fork	*get_fork(t_fork *forks, int index)
{
	t_fork	*tmp;

	tmp = forks;
	if (index == 0)
		return (tmp);
	while (tmp)
	{
		if (tmp->id == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
