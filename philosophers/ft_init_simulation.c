/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:51:10 by moichou           #+#    #+#             */
/*   Updated: 2024/05/27 20:04:13 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_appand_philosopher(t_philosopher **head, t_philosopher *node)
{
	t_philosopher	*tmp;

	tmp = *head;
	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	while (tmp->id != 1)
		tmp = tmp->next;
	tmp->next = node;
	node->next = *head;
}

static t_philosopher	*ft_create_philos(t_philoinfo *info)
{
	t_philosopher	*lst;
	t_philosopher	*node;
	int				id;

	lst = NULL;
	id = 1;
	while (info->number_of_philosophers--)
	{
		node = malloc(sizeof(t_philosopher));
		node->id = id;
		node->info = info;
		id++;
		ft_appand_philosopher(&lst, node);
	}
	return (lst);
}

void	ft_init_simulation(int ac, char **av)
{
	t_philosopher	*head;
	t_philoinfo		info;
	struct timeval	a;
	int				i;

	gettimeofday(&a, NULL);
	i = 0;
	info.number_of_philosophers = ft_atoi(av[1]);
	info.time_to_die = ft_atoi(av[2]);
	info.time_to_eat = ft_atoi(av[3]);
	info.time_to_sleep = ft_atoi(av[4]);
	info.timestamp = a;
	if (ac == 6)
		info.number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		info.number_of_times_each_philosopher_must_eat = 0;
	head = ft_create_philos(&info);
	if (!head)
		return ;
	// start simulation
	t_philosopher *tmp = head;
	while (tmp)
	{
		pthread_t philo;
		pthread_create(&philo, NULL, &ft_routine, head);
		pthread_join(philo, NULL);
		tmp = tmp->next;
		if (tmp && tmp->id == 1)
			break ;
	}
}
