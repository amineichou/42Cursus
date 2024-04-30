/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unputnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:51:10 by moichou           #+#    #+#             */
/*   Updated: 2023/11/27 16:05:14 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_putnbr(unsigned int n, int *length)
{
	if (n > 9)
	{
		ft_unsigned_putnbr(n / 10, length);
		ft_unsigned_putnbr(n % 10, length);
	}
	else
		ft_putchar(n + 48, length);
}
