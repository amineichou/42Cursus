/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:40:26 by moichou           #+#    #+#             */
/*   Updated: 2024/03/09 12:54:52 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_printerror(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(2, &msg[i], 1);
		i++;
	}
	exit(1);
}

static void	ft_initial_to_stof(double *res, double *fraction, int *sign)
{
	*res = 0.0;
	*fraction = 0.1;
	*sign = 1;
}

static void	ft_handle_double_part(double *result,
		const char *str, double *fraction)
{
	while (*str >= '0' && *str <= '9')
	{
		*result += *fraction * (*str - '0');
		*fraction *= 0.1;
		str++;
	}
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	int		sign;

	ft_initial_to_stof(&result, &fraction, &sign);
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		ft_handle_double_part(&result, str, &fraction);
	}
	return (result * sign);
}
