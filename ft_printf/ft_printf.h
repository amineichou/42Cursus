/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:02:57 by moichou           #+#    #+#             */
/*   Updated: 2023/12/08 15:24:49 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
void	ft_putchar(char c, int *length);
int		ft_putstr(char *s, int *length);
void	ft_putnbr(int n, int *length);
void	ft_puthex(unsigned long number, char form, int *length);
void	ft_unsigned_putnbr(unsigned int n, int *length);

#endif