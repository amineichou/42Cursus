/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:24:47 by moichou           #+#    #+#             */
/*   Updated: 2024/05/22 14:38:47 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi_check_long(char *str)
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
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_check_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && str[i] == '+')
		{
			i++;
			while (str[i])
			{
				if (str[i] == '+')
					return (-1);
				i++;
			}
		}
		if (str[i])
			i++;
	}
	return (0);
}

static int	ft_isvalid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '+')
			return (0);
		i++;
	}
	if (ft_check_sign(str) == -1 || ft_atoi_check_long(str) == -1)
		return (0);
	return (1);
}

static void ft_checkerror(int i)
{
	i -= 1;
	char *test[] = {"number_of_philosophers", "time_to_die",\
	"time_to_eat", "time_to_sleep",\
	"number_of_times_each_philosopher_must_eat"};
	ft_printerror("\033[0;31m");
	ft_printerror(test[i]);
	ft_printerror("\033[0;0m");
	ft_printerror(" not a valid number.\n");
}

int	ft_parser(char **av, int ac)
{
	int	i;

	i  = 1;
	while (i < ac)
	{
		if (!ft_isvalid_number(av[i]))
			return (ft_checkerror(i), 0);
		i++;
	}
	return (1);
}
