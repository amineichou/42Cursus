/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:51:10 by moichou           #+#    #+#             */
/*   Updated: 2024/06/03 19:55:03 by moichou          ###   ########.fr       */
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
		node->next = NULL;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
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

static t_philosopher	*ft_create_philos(t_philoinfo *info, t_fork *forks)
{
	t_philosopher	*lst;
	t_philosopher	*node;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	rotine;
	pthread_mutex_t last_meal_lock;
	int				id;

	lst = NULL;
	id = 1;
	pthread_mutex_init(&lock_print, NULL);
	pthread_mutex_init(&rotine, NULL);
	if (0 != pthread_mutex_init(&last_meal_lock, NULL))
		perror("init");
	int i = info->number_of_philosophers;
	while (i--)
	{
		node = ft_malloc(sizeof(t_philosopher));
		node->id = id;
		node->info = info;
		node->lock_print = &lock_print;
		node->last_meal = 0;
		node->fst_fork = get_fork(forks, id);
		if (id == info->number_of_philosophers)
			node->sec_fork= get_fork(forks, 0);
		else
			node->sec_fork = get_fork(forks, id + 1);
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

t_fork	*ft_create_forks(t_philoinfo *info)
{
	t_fork	*lst;
	t_fork	*node;
	int		id;
	int		philo_num;

	lst = NULL;
	id = 1;
	philo_num = info->number_of_philosophers;
	while (philo_num)
	{
		node = ft_malloc(sizeof(t_fork));
		node->id = id;
		node->next = NULL;
		if (-1 == pthread_mutex_init(&node->lock, NULL))
			perror("init");
		ft_append_fork(&lst, node);
		id++;
		philo_num--;
	}
	return (lst);
}

void	ft_init_simulation(int ac, char **av)
{
	t_philosopher	*head;
	t_philoinfo		info;
	t_fork			*forks;
	int				i;

	i = 0;
	info.number_of_philosophers = ft_atoi(av[1]);
	info.time_to_die = ft_atoi(av[2]);
	info.time_to_eat = ft_atoi(av[3]);
	info.time_to_sleep = ft_atoi(av[4]);
	info.philo_died = 0;
	if (ac == 6)
		info.num__must_eat = ft_atoi(av[5]);
	else
		info.num__must_eat = -1;
	info.start_time = ft_get_time();
	pthread_mutex_init(&info.philo_died_lock, NULL);
	// create forks
	forks = ft_create_forks(&info);
	// create philosphers
	head = ft_create_philos(&info, forks);
	if (!head)
		return ;
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
	tmp = head;
	while (tmp)
	{
		pthread_join(tmp->id_thread, NULL);
		tmp = tmp->next;
	}
	pthread_join(monitor_th, NULL);
}
