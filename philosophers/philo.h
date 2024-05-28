/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:16:23 by moichou           #+#    #+#             */
/*   Updated: 2024/05/28 21:56:03 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILO_H
#define FILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <sys/time.h>
#include <stdbool.h>

typedef struct s_philoinfo
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	bool			philo_died;
	struct timeval	timestamp;
}	t_philoinfo;

typedef struct s_philosopher
{
	int						id;
	t_philoinfo				*info;
	struct s_philosopher	*next;
	pthread_t				id_thread;
}	t_philosopher;

int		ft_parser(char **av, int ac);
int		ft_isdigit(char c);
int		ft_isspace(char c);
void	ft_printerror(char *msg);
int		ft_atoi(const char *str);
void	ft_init_simulation(int ac, char **av);
void	*ft_routine(void *arg);

#endif