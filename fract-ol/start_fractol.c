/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:22:55 by moichou           #+#    #+#             */
/*   Updated: 2024/03/09 17:46:55 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_start_fractol(t_fractol_data *fractol)
{
	fractol->mlx_ptr = mlx_init();
	if (!fractol->mlx_ptr)
		ft_printerror("Error connection!\n");
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr,
			WIDTH, HEIGHT, fractol->name);
	if (!fractol->win_ptr)
	{
		free(fractol->mlx_ptr);
		ft_printerror("Error creating window\n");
	}
	fractol->img.img = mlx_new_image(fractol->mlx_ptr, WIDTH, HEIGHT);
	if (!fractol->img.img)
	{
		mlx_destroy_window(fractol->mlx_ptr, fractol->win_ptr);
		free(fractol->mlx_ptr);
		ft_printerror("Error creating image\n");
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel,
			&fractol->img.line_length,
			&fractol->img.endian);
	ft_set_data(fractol);
}
