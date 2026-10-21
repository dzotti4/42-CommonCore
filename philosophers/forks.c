/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:32:04 by dzotti            #+#    #+#             */
/*   Updated: 2025/09/19 16:32:04 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	forks_destroy_partial(pthread_mutex_t *forks, int i)
{
	int	j;

	if (!forks || i <= 0)
		return ;
	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&forks[j]);
		j++;
	}
}

int	forks_init(pthread_mutex_t **forks, int n)
{
	int	i;

	if (!forks || n <= 0)
		return (0);
	*forks = (pthread_mutex_t *)malloc(sizeof(**forks) * n);
	if (!*forks)
		return (0);
	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL) != 0)
		{
			forks_destroy_partial(*forks, i);
			free(*forks);
			*forks = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

void	forks_destroy(pthread_mutex_t *forks, int n)
{
	int	i;

	if (!forks || n <= 0)
		return ;
	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}
