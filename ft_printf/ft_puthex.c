/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:52:27 by moichou           #+#    #+#             */
/*   Updated: 2023/12/07 22:25:54 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_lower(unsigned long x, int *length)
{
	if (x >= 16)
		ft_puthex_lower(x / 16, length);
	write(1, &"0123456789abcdef"[x % 16], 1);
	(*length)++;
}

static void	ft_puthex_upper(unsigned long x, int *length)
{
	if (x >= 16)
		ft_puthex_upper(x / 16, length);
	write(1, &"0123456789ABCDEF"[x % 16], 1);
	(*length)++;
}

void	ft_puthex(unsigned long number, char form, int *length)
{
	if (form == 'x')
		ft_puthex_lower(number, length);
	else if (form == 'X')
		ft_puthex_upper(number, length);
}
