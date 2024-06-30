/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:16:23 by moichou           #+#    #+#             */
/*   Updated: 2024/06/30 16:24:18 by moichou          ###   ########.fr       */
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
	long			start_time;
	bool			philo_died;
	pthread_mutex_t	philo_died_lock;
	t_fork			*forks;
}	t_philoinfo;

typedef struct s_philosopher
{
	int						id;
	long					last_meal;
	pthread_t				id_thread;
	t_fork					*fst_fork;
	t_fork					*sec_fork;
	t_philoinfo				*info;
	pthread_mutex_t			lock_print;
	pthread_mutex_t			last_meal_lock;
	struct s_philosopher	*next;
}	t_philosopher;

typedef enum s_routine
{
	EAT,
	SLEEP,
	THINK
}	t_routine;

int			ft_parser(char **av, int ac);
int			ft_isdigit(char c);
int			ft_isspace(char c);
void		*ft_malloc(int size);
void		ft_printerror(char *msg);
int			ft_atoi(const char *str);
void		ft_safe_print(t_philosopher *philo, char *message, t_routine routine);
long		ft_get_time(void);
char		*ft_get_routine(t_routine routine);
void		ft_usleep(long time);
void		ft_init_simulation(int ac, char **av);
void		*ft_routine(void *arg);
void		ft_monitor(t_philosopher *head);
bool		check_health(t_philosopher *philo);


/* FUNCTIONS */
void	ft_set_val(pthread_mutex_t *mtx, long *value, long new);
long	ft_get_val(pthread_mutex_t *mtx, long value);
void	ft_set_val_b(pthread_mutex_t *mtx, bool *value, bool new);
bool	ft_get_val_b(pthread_mutex_t *mtx, bool value);

#endif