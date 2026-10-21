/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:25:44 by dzotti            #+#    #+#             */
/*   Updated: 2025/05/06 14:25:44 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long n, int upper)
{
	char	*base;
	int		count;

	count = 0;
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_put_hex(n / 16, upper);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_put_ptr(void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_put_hex((unsigned long)p, 0);
	return (count);
}

int	handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_put_hex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), 1));
	if (c == 'p')
		return (ft_put_ptr(va_arg(args, void *)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
