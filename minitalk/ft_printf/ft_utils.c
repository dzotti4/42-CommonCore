/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:33:30 by dzotti            #+#    #+#             */
/*   Updated: 2025/05/06 14:33:30 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int	ft_putnbr(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int	ft_put_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_put_unsigned(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}
