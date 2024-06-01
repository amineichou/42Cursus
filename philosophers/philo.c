/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:16:03 by moichou           #+#    #+#             */
/*   Updated: 2024/06/01 21:42:53 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	test(t_philoinfo *info)
{
	printf("number_of_philosophers : %d\n", info->number_of_philosophers);
	printf("time_to_die : %d\n", info->time_to_die);
	printf("time_to_eat : %d\n", info->time_to_eat);
	printf("time_to_sleep : %d\n", info->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat : %d\n", info->num__must_eat);
}


int main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (ft_parser(av, ac))
			ft_init_simulation(ac, av);
	}
	else if (ac > 1)
		ft_printerror("no valid arguments\n");
	else
		ft_printerror("arguments required\n");
	return (0);
}
