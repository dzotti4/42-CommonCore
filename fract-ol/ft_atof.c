/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:43:20 by dzotti            #+#    #+#             */
/*   Updated: 2025/08/02 13:43:20 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_char(const char *str, int *dot_count, int *digit_count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (*dot_count == 1)
				return (1);
			(*dot_count)++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			(*digit_count)++;
		else
			return (1);
		i++;
	}
	return (0);
}

int	valid_double(const char *str)
{
	int	i;
	int	dot_count;
	int	digit_count;

	i = 0;
	dot_count = 0;
	digit_count = 0;
	if (!str)
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i] || (str[i] != '.' && !ft_isdigit(str[i])))
		return (1);
	if (is_valid_char(&str[i], &dot_count, &digit_count))
		return (1);
	if (digit_count == 0)
		return (1);
	return (0);
}

static double	parse_fraction(const char *str, int *i)
{
	double	fraction;
	double	result;

	fraction = 0.1;
	result = 0.0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result += (str[*i] - '0') * fraction;
		fraction *= 0.1;
		(*i)++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	if (!str)
		return (0.0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		result += parse_fraction(str, &i);
	}
	return (result * sign);
}
