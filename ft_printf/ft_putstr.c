/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:49:08 by moichou           #+#    #+#             */
/*   Updated: 2023/11/27 22:51:12 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int *length)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		ft_putchar(s[i], length);
		i++;
	}
	return (1);
}
