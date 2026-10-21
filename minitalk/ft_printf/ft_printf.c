/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:46:05 by dzotti            #+#    #+#             */
/*   Updated: 2025/05/06 10:46:05 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += handle_format(format[i + 1], arg);
			i += 2;
		}
		else
		{
			count += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(arg);
	return (count);
}
