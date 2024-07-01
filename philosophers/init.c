/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:51:07 by moichou           #+#    #+#             */
/*   Updated: 2024/07/01 18:37:04 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// bool	check_death(t_philosopher *philo)
// {
// 	long	        tmp;

// 	pthread_mutex_lock(&(philo->last_meal_lock));
// 	tmp = philo->last_meal;
// 	pthread_mutex_unlock(&(philo->last_meal_lock));
// 	if (ft_get_time() - tmp > philo->info->time_to_die)
// 	{
// 		set_val_b(&(philo->info->philo_died_lock), &(philo->info->philo_died), true);
// 		safe_print_r(philo->info, philo->id, "died");
// 		return (0);
// 	}
// 	return (1);
// }

// void	ft_monitor(t_philosopher *head)
// {
// 	t_philosopher	*philo;

// 	philo = head;
// 	while (check_death(philo))
// 	{
// 		if (philo->next == NULL)
// 			philo = head;
// 		else
// 			philo = philo->next;
// 	}
// }

t_philosopher	*init(t_philoinfo *info)
{
	t_philosopher	*head;
	t_fork			*forks;

	// create forks
	forks = create_forks(info);
	// create philosphers
	head = create_philos(info, forks);
	if (!head)
		return (NULL);
	return (head);
}
