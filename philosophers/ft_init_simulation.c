/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:51:10 by moichou           #+#    #+#             */
/*   Updated: 2024/06/01 21:45:32 by moichou          ###   ########.fr       */
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
		node->next = (*head);
		return ;
	}
	tmp = tmp->next;
	while (tmp->next->id != 1)
		tmp = tmp->next;
	tmp->next = node;
	node->next = (*head);
}

static t_philosopher	*ft_create_philos(t_philoinfo *info)
{
	t_philosopher	*lst;
	t_philosopher	*node;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_die_time;
	pthread_mutex_t	lock_var_died;
	pthread_mutex_t	rotine;
	int				id;

	lst = NULL;
	id = 1;
	pthread_mutex_init(&lock_print, NULL);
	pthread_mutex_init(&lock_die_time, NULL);
	pthread_mutex_init(&lock_var_died, NULL);
	pthread_mutex_init(&rotine, NULL);
	int i = info->number_of_philosophers;
	while (i--)
	{
		node = malloc(sizeof(t_philosopher));
		node->id = id;
		node->info = info;
		node->lock_print = &lock_print;
		node->lock_die_time = &lock_die_time; 
		node->lock_var_died = &lock_var_died; 
		node->rotine = &rotine;
		id++;
		ft_appand_philosopher(&lst, node);
	}
	return (lst);
}

void ft_append_fork(t_fork **lst, t_fork *node)
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

t_fork	*ft_create_forks(int number_of_philosophers)
{
	t_fork	*lst;
	t_fork	*node;
	int		id;

	lst = NULL;
	id = 1;
	number_of_philosophers++;
	while (number_of_philosophers)
	{
		node = malloc(sizeof(t_fork));
		if (!node)
			exit(1);
		node->id = id;
		node->next = NULL;
		ft_append_fork(&lst, node);
		id++;
		number_of_philosophers--;
	}
	return (lst);
}

void	ft_init_simulation(int ac, char **av)
{
	t_philosopher	*head;
	t_philoinfo		info;
	t_fork			*forks;
	struct timeval	a;
	int				i;

	gettimeofday(&a, NULL);
	i = 0;
	info.number_of_philosophers = ft_atoi(av[1]);
	info.time_to_die = ft_atoi(av[2]);
	info.time_to_eat = ft_atoi(av[3]);
	info.time_to_sleep = ft_atoi(av[4]);
	info.philo_died = 0;
	info.timestamp = a;
	if (ac == 6)
		info.num__must_eat = ft_atoi(av[5]);
	else
		info.num__must_eat = -1;
	// create philosphers
	head = ft_create_philos(&info);
	if (!head)
		return ;
	// create forks
	forks = ft_create_forks(info.number_of_philosophers);
	// create monitor thread
	pthread_t	monitor_th;
	pthread_create(&monitor_th, NULL, &ft_monitor, head);
	// create threads
	t_philosopher *tmp = head;
	while (tmp)
	{
		pthread_create(&tmp->id_thread, NULL, &ft_routine, tmp);
		tmp = tmp->next;
	}
	// start simulation
	while (tmp)
	{
		pthread_join(tmp->id_thread, NULL);
		tmp = tmp->next;
	}
	pthread_join(monitor_th, NULL);
}
