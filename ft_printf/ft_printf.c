/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:47:10 by moichou           #+#    #+#             */
/*   Updated: 2023/12/09 17:28:51 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_arg(const char c, va_list args, int *length)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), length);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), length);
	else if (c == 's')
	{
		if (!ft_putstr(va_arg(args, char *), length))
			ft_putstr("(null)", length);
	}
	else if (c == '%')
		ft_putchar(c, length);
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), 'X', length);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), 'x', length);
	else if (c == 'p')
	{
		ft_putstr("0x", length);
		ft_puthex((unsigned long)va_arg(args, void *), 'x', length);
	}
	else if (c == 'u')
		ft_unsigned_putnbr(va_arg(args, unsigned int), length);
	else
		ft_putchar(c, length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, format);
	length = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			ft_put_arg(*format, args, &length);
		}
		else
			ft_putchar(*format, &length);
		format++;
	}
	va_end(args);
	return (length);
}
