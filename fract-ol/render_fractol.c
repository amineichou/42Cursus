/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:39:03 by moichou           #+#    #+#             */
/*   Updated: 2024/03/09 18:47:40 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// linear interpolation y = y1 + ((x−x1) * (y2−y1) / x2−x1)
static double	scale_down(double unscaled, double new_min,
				double new_max, double old_max)
{
	return (unscaled / old_max * (new_max - new_min) + new_min);
}

// z(n+1) = z(n)^2 + c
static void	ft_draw_mandelbrot(int x, int y, t_fractol_data *fractol)
{
	t_complex_number	z;
	t_complex_number	c;
	int					color;
	int					i;

	z.x = 0;
	z.y = 0;
	c.x = (scale_down(x, -2, +2, WIDTH) * fractol->zoom_factor);
	c.y = (scale_down(y, -2, +2, HEIGHT) * fractol->zoom_factor);
	i = 0;
	while (i < fractol->iterations)
	{
		z = ft_sum(ft_square(z), c);
		color = scale_down(i, COLOR_BLACK, COLOR_WHITE, fractol->iterations);
		if ((z.x * z.x) + (z.y * z.y) > fractol->exit_point)
		{
			ft_put_pixel(fractol, x, y, color);
			return ;
		}
		i++;
	}
	ft_put_pixel(fractol, x, y, COLOR_BLACK);
}

// z = z^2 + c
static void	ft_draw_julia(int x, int y, t_fractol_data *fractol)
{
	t_complex_number	z;
	t_complex_number	c;
	int					color;
	int					i;

	z.x = scale_down(x, -2, +2, WIDTH) * fractol->zoom_factor;
	z.y = scale_down(y, -2, +2, HEIGHT) * fractol->zoom_factor;
	c.x = fractol->x_julia;
	c.y = fractol->y_julia;
	i = 0;
	while (i < fractol->iterations)
	{
		z = ft_sum(ft_square(z), c);
		color = scale_down(i, COLOR_WHITE, COLOR_BLACK, fractol->iterations);
		if ((z.x * z.x) + (z.y * z.y) > fractol->exit_point)
		{
			ft_put_pixel(fractol, x, y, color);
			return ;
		}
		i++;
	}
	ft_put_pixel(fractol, x, y, COLOR_BLACK);
}

void	ft_render_fractol(t_fractol_data *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fractol->fractal_type == 1)
				ft_draw_mandelbrot(x, y, fractol);
			else if (fractol->fractal_type == 2)
				ft_draw_julia(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img, 0, 0);
}
