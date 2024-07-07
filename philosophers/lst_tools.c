/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:35:13 by moichou           #+#    #+#             */
/*   Updated: 2024/07/07 12:03:35 by moichou          ###   ########.fr       */
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
	id = 0;
	while (++id <= info->philo_total)
	{
		node = malloc(sizeof(t_philosopher));
		if (!node)
			return (NULL);
		node->id = id;
		node->last_meal = ft_get_time();
		node->info = info;
		node->eaten_meals = 0;
		node->fst_fork = get_fork(forks, id);
		if (id == info->philo_total)
			node->sec_fork = get_fork(forks, 1);
		else
			node->sec_fork = get_fork(forks, id + 1);
		pthread_mutex_init(&node->eaten_meals_lock, NULL);
		pthread_mutex_init(&node->last_meal_lock, NULL);
		appand_philosopher(&lst, node);
	}
	return (lst);
}

static void	append_fork(t_fork **lst, t_fork *node)
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
		node = malloc(sizeof(t_fork));
		if (!node)
			return (NULL);
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
	while (tmp)
	{
		if (tmp->id == index)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
