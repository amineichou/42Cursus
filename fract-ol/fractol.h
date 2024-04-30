/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:37:19 by moichou           #+#    #+#             */
/*   Updated: 2024/03/10 10:58:43 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>

# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 800
# endif

# define COLOR_BLACK 0x000000
# define COLOR_WHITE 0xFFFFFF
# define COLOR_BLUE 0x0000FF

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_fractol_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*name;
	double	exit_point;
	int		iterations;
	int		fractal_type;
	double	zoom_factor;
	double	x_julia;
	double	y_julia;
	t_image	img;
}	t_fractol_data;

typedef struct s_complex_number
{
	// real number
	double	y;
	// imaginary number i
	double	x;
}	t_complex_number;

// start fractol
void				ft_start_fractol(t_fractol_data *fractol);

// render fractol
void				ft_render_fractol(t_fractol_data *fractol);

// utils
void				ft_printerror(char *msg);
double				ft_atof(const char *str);

// libft
int					ft_strcmp(char *s1, char *s2);
int					ft_isdigit(char c);

// tools
void				ft_put_pixel(t_fractol_data *fractol,
						int x, int y, int color);

// math
t_complex_number	ft_sum(t_complex_number z1, t_complex_number z2);
t_complex_number	ft_square(t_complex_number z);
void				ft_set_data(t_fractol_data *fractol);

// events
void				ft_start_events(t_fractol_data *fractol);

#endif