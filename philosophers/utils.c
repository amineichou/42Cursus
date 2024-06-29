/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:23:00 by moichou           #+#    #+#             */
/*   Updated: 2024/06/01 21:46:35 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

void	ft_printerror(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write (2, &msg[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

void	ft_appand_philosopher(t_philosopher **head, t_philosopher *node)
{
	t_philosopher	*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		(*head) = node;
		node->next = NULL;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
}


void	*ft_malloc(int size)
{
	void	*ptr = malloc(size);
	if (!size)
	{
		ft_printerror("malloc error !\n");
		exit(1);
	}
	return (ptr);
}

void	ft_safe_print(t_philosopher *philo, char *message, t_routine routine)
{
	pthread_mutex_lock(philo->lock_print);
	printf("%lld %d %s %s...\n", ft_get_time(), philo->id, message, ft_get_routine(routine));
	pthread_mutex_unlock(philo->lock_print);
}

char *ft_get_routine(t_routine routine)
{
	if (routine == 0)
		return ("eating");
	else if (routine == 1)
		return ("sleeping");
	else if (routine == 2)
		return ("thinking");
	return ("");
}

long long	ft_get_time(void)
{
	struct timeval	timestamp;
	gettimeofday(&timestamp, NULL);
	return ((long long)timestamp.tv_sec * 1000 + (long long)timestamp.tv_usec / 1000);
}

void	ft_usleep(size_t time)
{
	long	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
	{
		usleep(1);
	}
}
