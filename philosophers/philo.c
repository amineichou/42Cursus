/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:11:23 by moichou           #+#    #+#             */
/*   Updated: 2024/07/05 17:26:56 by moichou          ###   ########.fr       */
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
	t_philosopher   *tmp;

	tmp = head;
	while (tmp)
	{
		pthread_join(tmp->id_thread, NULL);
		tmp = tmp->next;
	}
}

void	*monitor(void *args)
{
	t_philosopher	*philos;
	long			time;
	int				is_full;

	while (true)
	{
		philos = (t_philosopher *)args;
		if (philos->info->meals_total != -1 && is_full == philos->info->philo_total)
		{
			set_val_b(&philos->info->philo_died_lock, &philos->info->philo_died, true);
			return (NULL);
		}
		is_full = 0;
		while (philos)
		{
			time = ft_get_time();
			if (time - get_val(&philos->last_meal_lock, &philos->last_meal) > philos->info->time_to_die
				&& (get_val(&philos->eaten_meals_lock, &philos->eaten_meals) < philos->info->meals_total || philos->info->meals_total == -1))
			{
				safe_print_r(philos->info, philos->id, "died");
				set_val_b(&philos->info->philo_died_lock, &philos->info->philo_died, true);
				return (NULL);
			}
			if (get_val(&philos->eaten_meals_lock, &philos->eaten_meals) >= philos->info->meals_total)
				is_full++;
			philos = philos->next;
		}
	}
	return (NULL);
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
	pthread_mutex_init(&info.print_lock, NULL);
	return (info);
}

/*
	input : philo_total		time_to_die		time_to_eat		time_to_sleep		meals_total[optional]
*/

int main(int ac, char **av)
{
	t_philosopher	*philo;
	t_philoinfo		info;
	pthread_t		th_monitor;

	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if (parser(av, ac))
		{
			info = create_info(ac, av);
			if (info.philo_total == 0 || info.meals_total == 0)
				return (0);
			philo = init(&info);
			if (!philo)
				return (0);
			start_simulation(philo);
			pthread_create(&th_monitor, NULL, monitor, philo);
			end_simulation(philo);
			pthread_join(th_monitor, NULL);
		}
	}
	else
		ft_printerror("no valid arguments\n");
	return (0);
}
