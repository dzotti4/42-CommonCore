/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 00:03:04 by dzotti            #+#    #+#             */
/*   Updated: 2025/08/02 00:03:04 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 600

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			max;
	int			fractal_type;
	t_complex	julia_c;
}	t_data;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
	int	color;
}	t_rgb;

int		mandelbrot(t_complex c, t_data *data);
void	put_pixel(t_data *data, int x, int y, int color);
void	render(t_data *data);
int		handle_key(int keycode, t_data *data);
int		handle_close(t_data *data);
int		handle_mouse(int button, int x, int y, t_data *data);
int		julia(t_complex z, t_data *data);
double	ft_atof(const char *str);
int		valid_double(const char *str);

#endif
