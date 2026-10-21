/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:10:18 by dzotti            #+#    #+#             */
/*   Updated: 2025/09/03 13:10:18 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_safe_log(t_job *a, const char *msg)
{
	if (stop_get(a->stop, a->stop_mtx))
		return ;
	pthread_mutex_lock(a->print_mtx);
	if (!stop_get(a->stop, a->stop_mtx))
		log_state(a->start_ms, a->id, msg);
	pthread_mutex_unlock(a->print_mtx);
}

void	action_take_forks(t_job *a)
{
	if (a->left == a->right)
	{
		pthread_mutex_lock(&a->forks[a->left]);
		action_safe_log(a, "has taken a fork");
		return ;
	}
	if ((a->id % 2) == 1)
	{
		pthread_mutex_lock(&a->forks[a->left]);
		action_safe_log(a, "has taken a fork");
		pthread_mutex_lock(&a->forks[a->right]);
		action_safe_log(a, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&a->forks[a->right]);
		action_safe_log(a, "has taken a fork");
		pthread_mutex_lock(&a->forks[a->left]);
		action_safe_log(a, "has taken a fork");
	}
}

void	action_eat_and_release(t_job *a)
{
	action_safe_log(a, "is eating");
	ms_sleep(a->t_eat);
	pthread_mutex_lock(a->meal_mtx);
	a->last_meal[a->id - 1] = now_ms();
	a->meals[a->id - 1] += 1;
	pthread_mutex_unlock(a->meal_mtx);
	if (a->left == a->right)
		pthread_mutex_unlock(&a->forks[a->left]);
	else
	{
		pthread_mutex_unlock(&a->forks[a->left]);
		pthread_mutex_unlock(&a->forks[a->right]);
	}
}

void	action_sleep_and_think(t_job *a)
{
	action_safe_log(a, "is sleeping");
	ms_sleep(a->t_sleep);
	action_safe_log(a, "is thinking");
	if (a->n_total % 2 == 1)
		ms_sleep(1);
}
