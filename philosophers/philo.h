/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:12:23 by moichou           #+#    #+#             */
/*   Updated: 2024/07/05 17:37:46 by moichou          ###   ########.fr       */
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

#define NOF "number_of_philosophers"
#define TTD "time_to_die"
#define TTE "time_to_eat"
#define TTS "time_to_sleep"
#define NOTEPME "number_of_times_each_philosopher_must_eat"

typedef struct s_fork
{
	pthread_mutex_t	lock;
	int				id;
	struct s_fork	*next;
}	t_fork;

typedef struct s_philoinfo
{
	int				philo_total;
	long			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_total;
	long			start_time;
	bool			philo_died;
	t_fork			*forks;
	pthread_mutex_t	philo_died_lock;
	pthread_mutex_t	print_lock;
}	t_philoinfo;

typedef struct s_philosopher
{
	int						id;
	pthread_t				id_thread;
	long					last_meal;
	pthread_mutex_t			last_meal_lock;
	long					eaten_meals;
	pthread_mutex_t			eaten_meals_lock;
	t_fork					*fst_fork;
	t_fork					*sec_fork;
	t_philoinfo				*info;
	struct s_philosopher	*next;
}	t_philosopher;

typedef enum s_routine
{
	EAT,
	SLEEP,
	THINK
}	t_routine;

/* main */
t_philosopher	*init(t_philoinfo *info);
void			*routine(void *arg);
int				parser(char **av, int ac);

/* utils */
int				ft_isdigit(char c);
int				ft_isspace(char c);
void			ft_printerror(char *msg);
int				ft_atoi(const char *str);
long			ft_get_time(void);
void			ft_usleep(long time, t_philoinfo *info);
void			safe_print_r(t_philoinfo *info, int philo_id, char *message);


/* routine */
void			*routine(void *arg);

/* lst_tools */
t_philosopher	*create_philos(t_philoinfo *info, t_fork *forks);
t_fork			*create_forks(t_philoinfo *info);
t_fork			*get_fork(t_fork *forks, int index);

/* mtx_tools */
long			get_val(pthread_mutex_t *mtx, long *value);
void			set_val(pthread_mutex_t *mtx, long *value, long new);
bool			get_val_b(pthread_mutex_t *mtx, bool *value);
void			set_val_b(pthread_mutex_t *mtx, bool *value, bool new);

#endif