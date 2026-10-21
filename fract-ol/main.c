/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:02:35 by dzotti            #+#    #+#             */
/*   Updated: 2025/08/18 17:12:08 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	valid_args(int argc, char **argv, t_data *data)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		data->fractal_type = 0;
		return (0);
	}
	else if (ft_strncmp (argv[1], "julia", 6) == 0)
	{
		data->fractal_type = 1;
		if (argc == 4 && valid_double(argv[2]) == 0
			&& valid_double(argv[3]) == 0)
		{
			data->julia_c.re = ft_atof(argv[2]);
			data->julia_c.im = ft_atof(argv[3]);
			return (0);
		}
		else if (argc == 2)
		{
			data->julia_c.re = -0.8;
			data->julia_c.im = 0.156;
			return (0);
		}
	}
	write(2, "Usage:  ./fractol mandelbrot\n", 29);
	write(2, "	./fractol julia [re] [im]\n", 28);
	return (1);
}

static int	prepare_window(t_data *data)
{
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->max = 1000;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!data->win)
		return (1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (1);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	if (!data->addr)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		write(2, "Usage:  ./fractol mandelbrot\n", 29);
		write(2, "	./fractol julia [re] [im]\n", 28);
		return (1);
	}
	if (valid_args(argc, argv, &data) != 0)
		return (1);
	if (prepare_window(&data) != 0)
		return (1);
	render(&data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
