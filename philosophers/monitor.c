/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:57:49 by dzotti            #+#    #+#             */
/*   Updated: 2025/09/21 22:57:49 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	death_snapshot(t_job *j, int i)
{
	long	lm;
	long	now;

	pthread_mutex_lock(j->meal_mtx);
	lm = j->last_meal[i];
	pthread_mutex_unlock(j->meal_mtx);
	now = now_ms();
	return (now - lm >= j->time_to_die);
}

static int	monitor_check_death(t_job *j, int i)
{
	if (!death_snapshot(j, i))
		return (0);
	pthread_mutex_lock(j->print_mtx);
	stop_set(j->stop, j->stop_mtx, 1);
	log_state(j->start_ms, i + 1, "died");
	pthread_mutex_unlock(j->print_mtx);
	return (1);
}

static int	monitor_check_full(t_job *j)
{
	int	i;

	if (j->must_eat <= 0)
		return (0);
	i = 0;
	pthread_mutex_lock(j->meal_mtx);
	while (i < j->n_total)
	{
		if (j->meals[i] < j->must_eat)
		{
			pthread_mutex_unlock(j->meal_mtx);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(j->meal_mtx);
	return (1);
}

void	*monitor_loop(void *ptr)
{
	t_job	*j;
	int		i;

	j = (t_job *)ptr;
	while (!stop_get(j->stop, j->stop_mtx))
	{
		i = 0;
		while (i < j->n_total)
		{
			if (monitor_check_death(j, i))
				return (NULL);
			i++;
		}
		if (monitor_check_full(j))
			return (NULL);
		ms_sleep(1);
	}
	return (NULL);
}
