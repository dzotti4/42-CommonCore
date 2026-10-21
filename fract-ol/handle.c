/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 22:47:16 by dzotti            #+#    #+#             */
/*   Updated: 2025/08/18 16:32:33 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	if (button == 4 || button == 5)
	{
		mouse_re = (x - WIDTH / 2.0) * (4.0 / WIDTH)
			* data->zoom + data->offset_x;
		mouse_im = (y - HEIGHT / 2.0) * (4.0 / WIDTH)
			* data->zoom + data->offset_y;
		if (button == 4)
			zoom_factor = 0.9;
		else
			zoom_factor = 1.1;
		data->zoom *= zoom_factor;
		data->offset_x = mouse_re - (x - WIDTH / 2.0)
			* (4.0 / WIDTH) * data->zoom;
		data->offset_y = mouse_im - (y - HEIGHT / 2.0)
			* (4.0 / WIDTH) * data->zoom;
		render(data);
	}
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 65307)
		return (handle_close(data));
	else if (keycode == 123 || keycode == 65361)
		data->offset_x -= 0.1 * data->zoom;
	else if (keycode == 124 || keycode == 65363)
		data->offset_x += 0.1 * data->zoom;
	else if (keycode == 125 || keycode == 65364)
		data->offset_y += 0.1 * data->zoom;
	else if (keycode == 126 || keycode == 65362)
		data->offset_y -= 0.1 * data->zoom;
	else
		return (0);
	render(data);
	return (0);
}

int	handle_close(t_data *data)
{
	if (data->mlx && data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	exit(0);
	return (0);
}
