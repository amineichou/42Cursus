/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:05 by moichou           #+#    #+#             */
/*   Updated: 2024/03/10 11:27:10 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mendelbrotset_parse(char *name, t_fractol_data *fractol)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
	{
		fractol->name = name;
		fractol->fractal_type = 1;
		return (1);
	}
	else
		ft_printerror("Args error!\n\
		try ./fractol mandelbrot\n\
		or ./fractol julia <reel> <i>\n");
	return (0);
}

static int	ft_julia_params_parse(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.'
			&& str[i] != '+' && str[i] != '-')
			return (-1);
		if (str[i] == '.' && str[i + 1]
			&& str[i + 1] == '.')
			return (-1);
		i++;
	}
	return (1);
}

static int	ft_juliaset_parse(char *name, char *x,
				char *y, t_fractol_data *fractol)
{
	if (ft_strcmp(name, "julia") == 0)
	{
		fractol->name = name;
		fractol->fractal_type = 2;
		if (ft_julia_params_parse(x) == -1 || ft_julia_params_parse(y) == -1)
			ft_printerror("error in agrs of julia!\n\
			you can try ./fractol julia <reel> <i>\n");
		fractol->x_julia = ft_atof(x);
		fractol->y_julia = ft_atof(y) * -1;
		return (1);
	}
	else
		ft_printerror("Args error!\nyou can try ./fractol julia <reel> <i>\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol_data	fractol;

	if (ac <= 1)
		ft_printerror("Args error!\n");
	else if (ac == 2)
	{
		if (ft_mendelbrotset_parse(av[1], &fractol))
		{
			ft_start_fractol(&fractol);
			ft_render_fractol(&fractol);
			ft_start_events(&fractol);
			mlx_loop(fractol.mlx_ptr);
		}
	}
	else if (ac == 4)
	{
		if (ft_juliaset_parse(av[1], av[2], av[3], &fractol))
		{
			ft_start_fractol(&fractol);
			ft_render_fractol(&fractol);
			ft_start_events(&fractol);
			mlx_loop(fractol.mlx_ptr);
		}
	}
	return (0);
}
