/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:16:03 by moichou           #+#    #+#             */
/*   Updated: 2024/06/30 20:53:07 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	test(t_philoinfo *info)
{
	printf("number_of_philosophers : %d\n", info->number_of_philosophers);
	printf("time_to_die : %ld\n", info->time_to_die);
	printf("time_to_eat : %d\n", info->time_to_eat);
	printf("time_to_sleep : %d\n", info->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat : %d\n", info->num__must_eat);
}


// void	start_simulation(t_philosopher *head)
// {
// 	// create threads
// 	// t_philosopher *tmp = head;
// 	// while (tmp)
// 	// {
// 	// 	pthread_create(&tmp->id_thread, NULL, ft_routine, tmp);
// 	// 	tmp = tmp->next;
// 	// }
// }

// void	end_simulation(t_philosopher *head)
// {
// 	t_philosopher *tmp = head;

// 	tmp = head;
// 	while (tmp)
// 	{
// 		pthread_join(tmp->id_thread, NULL);
// 		tmp = tmp->next;
// 	}
// }

int main(int ac, char **av)
{
	t_philosopher	*philo;
	t_philosopher	*tmp;

	if (ac == 5 || ac == 6)
	{
		if (ft_parser(av, ac))
		{
			philo = ft_init_simulation(ac, av);
			// start_simulation(philo);
			tmp = philo;
			while (tmp)
			{
				pthread_create(&tmp->id_thread, NULL, ft_routine, tmp);
				tmp = tmp->next;
			}
			printf("%ld\n", philo->info->start_time);
			ft_monitor(philo);
			// end_simulation(philo);
			tmp = philo;
			while (tmp)
			{
				pthread_join(tmp->id_thread, NULL);
				tmp = tmp->next;
			}
		}
	}
	else if (ac > 1)
		ft_printerror("no valid arguments\n");
	else
		ft_printerror("arguments required\n");
	return (0);
}
