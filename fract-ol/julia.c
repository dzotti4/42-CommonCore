/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:17:36 by dzotti            #+#    #+#             */
/*   Updated: 2025/08/01 23:17:36 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex z, t_data *data)
{
	t_complex	c;
	double		new_re;
	double		new_im;
	int			i;

	c = data->julia_c;
	i = 0;
	while (i < data->max)
	{
		if ((z.re * z.re + z.im * z.im) > 4)
			break ;
		new_re = z.re * z.re - z.im * z.im + c.re;
		new_im = 2 * z.re * z.im + c.im;
		z.re = new_re;
		z.im = new_im;
		i++;
	}
	return (i);
}
