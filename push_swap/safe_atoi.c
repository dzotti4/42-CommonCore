/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:41:14 by dzotti            #+#    #+#             */
/*   Updated: 2025/06/25 21:41:14 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	handle_space_sign(char *str, int *i, int *sign)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (str[*i] < '0' || str[*i] > '9')
		return (0);
	return (1);
}

int	safe_atoi(char *str, int *result)
{
	int		sign;
	long	nb;
	int		i;

	sign = 1;
	nb = 0;
	i = 0;
	if (!handle_space_sign(str, &i, &sign))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if ((nb * sign) > INT_MAX || (nb * sign) < INT_MIN)
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*result = (int)(nb * sign);
	return (1);
}
