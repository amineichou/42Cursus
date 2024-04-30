/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:34:54 by moichou           #+#    #+#             */
/*   Updated: 2024/03/10 10:52:44 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_number	ft_sum(t_complex_number z1, t_complex_number z2)
{
	t_complex_number	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

// real (x^2 - y^2)
// i = 2*x*y
t_complex_number	ft_square(t_complex_number z)
{
	t_complex_number	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

// 251
void	ft_set_data(t_fractol_data *fractol)
{
	fractol->exit_point = 4;
	fractol->iterations = 100;
	fractol->zoom_factor = 1.0;
}
