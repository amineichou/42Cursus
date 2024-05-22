/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:51:10 by moichou           #+#    #+#             */
/*   Updated: 2024/05/22 15:03:04 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_append_node(t_philosopher *head, t_philosopher *node)
{
	t_philosopher	*tmp;

	tmp = head;
	if (head == NULL)
	{
		head = node;
		return ;
	}
	while (tmp->id != 1)
		tmp = tmp->next;
	tmp->next = node;
	node->next = head;
}

static t_philosopher	*ft_create_philos(int ph_num)
{
	t_philosopher	*head;
	int				i;

	i = 1;
	head = NULL;
	while (i <= ph_num)
	{
		
		i++;
	}
}

void	ft_init_simulation(int ac, char **av)
{
	t_philosopher	*head;
	t_philoinfo		info;
	int				i;

	i = 0;
	info.number_of_philosophers = ft_atoi(av[1]);
	info.time_to_die = ft_atoi(av[2]);
	info.time_to_eat = ft_atoi(av[3]);
	info.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info.number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		info.number_of_times_each_philosopher_must_eat = 0;
	head = ft_create_philos(info.number_of_philosophers);
}