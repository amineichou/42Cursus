/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:51:10 by moichou           #+#    #+#             */
/*   Updated: 2024/06/30 16:25:54 by moichou          ###   ########.fr       */
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
	int				id;

	lst = NULL;
	id = 1;
	int i = info->number_of_philosophers;
	while (i--)
	{
		node = ft_malloc(sizeof(t_philosopher));
		node->id = id;
		node->info = info;
		node->last_meal = 0;
		node->fst_fork = get_fork(forks, id);
		if (id == info->number_of_philosophers)
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
		pthread_mutex_init(&node->last_meal_lock, NULL);
		pthread_mutex_init(&node->lock_print, NULL);
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
		pthread_mutex_init(&node->lock, NULL);
		ft_append_fork(&lst, node);
		id++;
		philo_num--;
	}
	return (lst);
}

bool	check_health(t_philosopher *philo)
{
	long	tmp;

	pthread_mutex_lock(&philo->last_meal_lock);
	tmp = philo->last_meal;
	pthread_mutex_unlock(&philo->last_meal_lock);
	if (ft_get_time() - tmp > philo->info->time_to_die)
	{
		pthread_mutex_lock(&philo->info->philo_died_lock);
		philo->info->philo_died = true;
		pthread_mutex_unlock(&philo->info->philo_died_lock);
		ft_safe_print(philo, "died", -1);
		return (0);
	}
	return (1);
}

void	ft_monitor(t_philosopher *head)
{
	t_philosopher	*philo;

	philo = head;
	while (philo && check_health(philo))
	{
		if (philo->next == NULL)
			philo = head;
		else
			philo = philo->next;
	}
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
	info.philo_died = false;
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
	// create threads
	t_philosopher *tmp = head;
	while (tmp)
	{
		pthread_create(&tmp->id_thread, NULL, ft_routine, tmp);
		tmp = tmp->next;
	}
	// create monitor thread
	ft_monitor(head);
	// start simulation
	tmp = head;
	while (tmp)
	{
		pthread_join(tmp->id_thread, NULL);
		tmp = tmp->next;
	}
}
