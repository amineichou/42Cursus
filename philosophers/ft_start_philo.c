/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:57:12 by moichou           #+#    #+#             */
/*   Updated: 2024/05/21 19:32:34 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_eat(void *arg)
{
	(void)arg;
	printf("eating...\n");
	pthread_exit(NULL);
}

void	*ft_sleep(void *arg)
{
	(void)arg;
	printf("sleeping...\n");
	pthread_exit(NULL);
}

void	*ft_think(void *arg)
{
	(void)arg;
	printf("thinking...\n");
	pthread_exit(NULL);
}

static void	ft_create_philos(int ph_num)
{
	pthread_t peat, psleep, pthink;

	while (ph_num--)
	{
		pthread_create(&peat, NULL, &ft_eat, NULL);
		pthread_create(&psleep, NULL, &ft_sleep, NULL);
		pthread_create(&pthink, NULL, &ft_think, NULL);
		pthread_join(peat, NULL);
		pthread_join(psleep, NULL);
		pthread_join(pthink, NULL);
	}
}

void	ft_start_philo(t_philo *info)
{
    ft_create_philos(info->number_of_philosophers);
}
