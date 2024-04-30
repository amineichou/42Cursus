/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:56:48 by moichou           #+#    #+#             */
/*   Updated: 2024/03/08 17:41:20 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_close(t_fractol_data *fractol)
{
	(void)fractol;
	exit(1);
}

static int	ft_keyhandle(int keycode, t_fractol_data *fractol)
{
	if (keycode == 53)
		ft_close(fractol);
	else if (keycode == 34)
	{
		fractol->iterations += 10;
		ft_render_fractol(fractol);
	}
	return (0);
}

static int	ft_mouse_handle(int button, int x, int y, t_fractol_data *fractol)
{
	if (button == 4)
	{
		fractol->zoom_factor *= 0.95;
		ft_render_fractol(fractol);
	}
	else if (button == 5)
	{
		fractol->zoom_factor *= 1.05;
		ft_render_fractol(fractol);
	}
	(void)x;
	(void)y;
	return (0);
}

void	ft_start_events(t_fractol_data *fractol)
{
	mlx_hook(fractol->win_ptr, 2, 0, ft_keyhandle, fractol);
	mlx_hook(fractol->win_ptr, 17, 0, ft_close, fractol);
	mlx_hook(fractol->win_ptr, 4, 0, ft_mouse_handle, fractol);
}
