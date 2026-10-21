/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:01:56 by dzotti            #+#    #+#             */
/*   Updated: 2025/09/21 21:01:56 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stop_get(int *stop, pthread_mutex_t *stop_mtx)
{
	int	i;

	pthread_mutex_lock(stop_mtx);
	i = *stop;
	pthread_mutex_unlock(stop_mtx);
	return (i);
}

void	stop_set(int *stop, pthread_mutex_t *stop_mtx, int i)
{
	pthread_mutex_lock(stop_mtx);
	*stop = i;
	pthread_mutex_unlock(stop_mtx);
}

static int	quota_met(t_job *a)
{
	int	done;

	if (a->must_eat <= 0)
		return (0);
	pthread_mutex_lock(a->meal_mtx);
	done = (a->meals[a->id - 1] >= a->must_eat);
	pthread_mutex_unlock(a->meal_mtx);
	return (done);
}

void	*worker_loop(void *ptr)
{
	t_job	*a;

	a = (t_job *)ptr;
	if ((a->id % 2) == 0)
		ms_sleep(a->t_eat / 2);
	while (!stop_get(a->stop, a->stop_mtx))
	{
		if (quota_met(a))
			break ;
		action_take_forks(a);
		if (a->left == a->right)
		{
			while (!stop_get(a->stop, a->stop_mtx))
				ms_sleep(1);
			pthread_mutex_unlock(&a->forks[a->left]);
			break ;
		}
		action_eat_and_release(a);
		if (quota_met(a))
			break ;
		action_sleep_and_think(a);
	}
	return (NULL);
}
