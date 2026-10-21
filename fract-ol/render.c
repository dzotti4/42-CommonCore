/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:20:56 by dzotti            #+#    #+#             */
/*   Updated: 2025/08/02 11:20:56 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_pixel(int x, int y, t_data *data)
{
	t_complex	c;
	t_complex	z;
	t_rgb		rgb;
	int			i;

	if (data->fractal_type == 0)
	{
		c.re = (x - WIDTH / 2.0) * (4.0 / WIDTH) * data->zoom + data->offset_x;
		c.im = (y - HEIGHT / 2.0) * (4.0 / WIDTH) * data->zoom + data->offset_y;
		i = mandelbrot(c, data);
	}
	else
	{
		z.re = (x - WIDTH / 2.0) * (4.0 / WIDTH) * data->zoom + data->offset_x;
		z.im = (y - HEIGHT / 2.0) * (4.0 / WIDTH) * data->zoom + data->offset_y;
		i = julia(z, data);
	}
	rgb.red = (i * 3) % 256;
	rgb.green = (i * 6) % 256;
	rgb.blue = (i * 9) % 256;
	rgb.color = (rgb.red << 16) | (rgb.green << 8) | rgb.blue;
	put_pixel(data, x, y, rgb.color);
}

void	render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
