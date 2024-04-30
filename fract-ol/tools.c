/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:41:54 by moichou           #+#    #+#             */
/*   Updated: 2024/03/09 19:02:25 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_put_pixel(t_fractol_data *fractol, int x, int y, int color)
{
	int	*dst;

	dst = (int *)fractol->img.addr + (y * WIDTH + x);
	*dst = color;
}
