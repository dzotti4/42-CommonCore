/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:31:49 by dzotti            #+#    #+#             */
/*   Updated: 2025/08/27 21:31:49 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_number(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *s)
{
	int		i;
	long	result;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	result = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		if (result > INT_MAX)
			return (0);
		i++;
	}
	return ((int)result);
}

static int	all_numbers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv, t_args *p)
{
	if (!p || argc < 5 || argc > 6)
		return (0);
	if (!all_numbers(argc, argv))
		return (0);
	p->n_of_philos = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		p->n_times_must_eat = ft_atoi(argv[5]);
	else
		p->n_times_must_eat = -1;
	if (p->n_of_philos <= 0 || p->n_of_philos > 200)
		return (0);
	if (p->time_to_die <= 0 || p->time_to_eat <= 0 || p->time_to_sleep <= 0)
		return (0);
	if (argc == 6 && p->n_times_must_eat <= 0)
		return (0);
	return (1);
}
