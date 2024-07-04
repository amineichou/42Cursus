/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:11:23 by moichou           #+#    #+#             */
/*   Updated: 2024/07/04 22:29:28 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_philosopher *head)
{
	t_philosopher	*tmp;

	tmp = head;
	// if (tmp->info->philo_total == 1)
	// {
	// 	pthread_create(&tmp->id_thread, NULL, routine, tmp);
	// 	pthread_detach(tmp->id_thread);
	// 	return ;
	// }
	while (tmp)
	{
		pthread_create(&tmp->id_thread, NULL, routine, tmp);
		if (tmp->id % 2)
			ft_usleep(100, head->info);
		tmp = tmp->next;
	}
}

void	end_simulation(t_philosopher *head)
{
	t_philosopher   *tmp;

	// tmp = head;
	// while (tmp)
	// {
	// 	// dprintf(2, "HELLO\n");
	// 	pthread_mutex_unlock(&tmp->fst_fork->lock);
	// 	pthread_mutex_unlock(&tmp->sec_fork->lock);
	// 	pthread_mutex_unlock(&tmp->info->print_lock);
	// 	pthread_mutex_unlock(&tmp->info->philo_died_lock);
	// 	pthread_mutex_unlock(&tmp->eaten_meals_lock);
	// 	pthread_mutex_destroy(&tmp->last_meal_lock);
	// 	pthread_mutex_destroy(&tmp->eaten_meals_lock);
	// 	pthread_mutex_destroy(&tmp->info->philo_died_lock);
	// 	pthread_mutex_destroy(&tmp->info->print_lock);
	// 	pthread_mutex_destroy(&tmp->fst_fork->lock);
	// 	pthread_mutex_destroy(&tmp->sec_fork->lock);
	// 	tmp = tmp->next;
	// }
	tmp = head;
	while (tmp)
	{
		pthread_detach(tmp->id_thread);
		tmp = tmp->next;
	}
}

void	*monitor(void *args)
{
	t_philosopher	*philos;
	long			time;
	int				i;

	philos = (t_philosopher *)args;
	while (true)
	{
		i = 0;
		while (++i < philos->info->philo_total)
		{
			time = ft_get_time();
			if (time - get_val(&philos->last_meal_lock, &philos->last_meal) > philos->info->time_to_die)
			{
				safe_print_r(philos->info, philos->id, "died");
				set_val_b(&philos->info->philo_died_lock, &philos->info->philo_died, true);
				return (NULL);
			}
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

		// t_philosopher	*tmp;

	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		if (parser(av, ac))
		{
			info = create_info(ac, av);
			philo = init(&info);
			start_simulation(philo);
			// monitor(philo);
			pthread_create(&th_monitor, NULL, monitor, philo);
			// if (info.philo_total != 1)
			// else
			// 	pthread_detach(philo->id_thread);
			end_simulation(philo);
			pthread_join(th_monitor, NULL);
		}
		else
			return (0);
	}
	else if (ac > 1)
		ft_printerror("no valid arguments\n");
	else
		ft_printerror("arguments required\n");
			// tmp = philo;
			// while (tmp)
			// {
			// 	dprintf(2, "[%ld]", get_val(&(tmp->eaten_meals_lock), &(tmp->eaten_meals)));
			// 	tmp = tmp->next;
			// }
	return (0);
}
