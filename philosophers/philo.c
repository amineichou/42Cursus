/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:11:23 by moichou           #+#    #+#             */
/*   Updated: 2024/07/03 14:36:00 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_philosopher *head)
{
	t_philosopher	*tmp;

	tmp = head;
	if (tmp->info->philo_total)
	{
		pthread_create(&tmp->id_thread, NULL, routine, tmp);
		pthread_detach(head->id_thread);
		return ;
	}
	while (tmp)
	{
		pthread_create(&tmp->id_thread, NULL, routine, tmp);
		if (tmp->id % 2)
			ft_usleep(100);
		tmp = tmp->next;
	}
}

void	end_simulation(t_philosopher *head)
{
	t_philosopher   *tmp;

	tmp = head;
	while (tmp)
	{
		pthread_join(tmp->id_thread, NULL);
		tmp = tmp->next;
	}
}

bool	check_death(t_philosopher *philo)
{
	long	tmp;

	tmp = get_val(&(philo->last_meal_lock), &(philo->last_meal));
	if (ft_get_time() - tmp > philo->info->time_to_die)
	{
		set_val_b(&(philo->info->philo_died_lock), &(philo->info->philo_died), true);
		safe_print_r(philo->info, philo->id, "died");
		return (0);
	}
	return (1);
}

void	monitor(t_philosopher *philos)
{
	t_philosopher	*tmp;

	tmp = philos;
	while (tmp && check_death(tmp))
	{
		if (tmp->next == NULL)
			tmp = philos;
		else
			tmp = tmp->next;
	}
}

t_philoinfo	create_info(int ac, char **av)
{
	t_philoinfo	info;

	info.philo_total = ft_atoi(av[1]);
	info.time_to_die = ft_atoi(av[2]);
	info.time_to_eat = ft_atoi(av[3]);
	info.time_to_sleep = ft_atoi(av[4]);
	info.philo_died = false;
	info.start_time = ft_get_time();
	if (ac == 6)
		info.meals_total = ft_atoi(av[5]);
	else
		info.meals_total = -1;
	pthread_mutex_init(&info.philo_died_lock, NULL);
	return (info);
}

/*
	input : philo_total		time_to_die		time_to_eat		time_to_sleep		meals_total[optional]
*/

int main(int ac, char **av)
{
	t_philosopher	*philo;
	t_philoinfo		info;

	if (ac == 5 || ac == 6)
	{
		if (parser(av, ac))
		{
			info = create_info(ac, av);
			philo = init(&info);
			start_simulation(philo);
			monitor(philo);
			// if (info.philo_total == 1)
			// {
			// 	pthread_detach(philo->id_thread);
			// }
			// else
			if (info.philo_total != 1)
				end_simulation(philo);
		}
		else
			return (0);
	}
	else if (ac > 1)
		ft_printerror("no valid arguments\n");
	else
		ft_printerror("arguments required\n");
	return (0);
}
