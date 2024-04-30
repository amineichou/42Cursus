/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:50:17 by moichou           #+#    #+#             */
/*   Updated: 2023/11/27 22:50:47 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *length)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, length);
		ft_putnbr(n % 10, length);
	}
	else if (n < 0)
	{
		ft_putchar('-', length);
		n *= -1;
		ft_putnbr(n, length);
	}
	else
		ft_putchar(n + 48, length);
}
