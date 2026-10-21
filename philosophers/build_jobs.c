/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:26:49 by dzotti            #+#    #+#             */
/*   Updated: 2025/09/23 16:26:49 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// koppel alle gedeelde pointers van jobs[0] aan een job
static void	copy_shared_to_job(t_job *job, const t_job *first)
{
	job->stop = first->stop;
	job->last_meal = first->last_meal;
	job->meals = first->meals;
	job->meal_mtx = first->meal_mtx;
	job->stop_mtx = first->stop_mtx;
	job->print_mtx = first->print_mtx;
	job->forks = first->forks;
	job->n_total = first->n_total;
}

// vul alle vaste velden voor 1 filosoof
static void	fill_job_fields(t_job *job, const t_args *a
, int index, long start_ms)
{
	job->id = index + 1;
	job->left = index;
	job->right = (index + 1) % a->n_of_philos;
	job->start_ms = start_ms;
	job->t_eat = a->time_to_eat;
	job->t_sleep = a->time_to_sleep;
	job->time_to_die = a->time_to_die;
	job->must_eat = a->n_times_must_eat;
}

// bouw alle jobs: starttijd, shared koppelen,..
void	build_jobs(t_job *jobs, const t_args *a)
{
	long	start_ms;
	int		i;

	start_ms = now_ms();
	i = 0;
	while (i < a->n_of_philos)
	{
		jobs[0].last_meal[i] = start_ms;
		jobs[0].meals[i] = 0;
		copy_shared_to_job(&jobs[i], &jobs[0]);
		fill_job_fields(&jobs[i], a, i, start_ms);
		i++;
	}
}
