/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:16:23 by moichou           #+#    #+#             */
/*   Updated: 2024/06/03 20:17:40 by moichou          ###   ########.fr       */
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


typedef struct s_fork
{
	pthread_mutex_t	lock;
	int				id;
	struct s_fork	*next;
}	t_fork;

typedef struct s_philoinfo
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num__must_eat;
	bool			philo_died;
	t_fork			*forks;
}	t_philoinfo;

typedef struct s_philosopher
{
	int						id;
	long					meals;
	pthread_t				id_thread;
	t_fork					*fst_fork;
	t_fork					*sec_fork;
	t_philoinfo				*info;
	pthread_mutex_t			*lock_print;
	pthread_mutex_t			*lock_die_time;
	pthread_mutex_t			*lock_var_died;
	pthread_mutex_t			*rotine;
	struct s_philosopher	*next;
}	t_philosopher;

typedef enum s_routine
{
	EAT,
	SLEEP,
	THINK
}	t_routine;

int		ft_parser(char **av, int ac);
int		ft_isdigit(char c);
int		ft_isspace(char c);
void	*ft_malloc(int size);
void	ft_printerror(char *msg);
int		ft_atoi(const char *str);
void	ft_init_simulation(int ac, char **av);
void	*ft_routine(void *arg);
void	*ft_monitor(void *arg);

#endif