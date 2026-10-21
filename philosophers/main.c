/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:51:14 by dzotti            #+#    #+#             */
/*   Updated: 2025/09/23 13:51:14 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	alloc_jobs_threads(const t_args *a, t_job **jobs,
pthread_t **workers)
{
	*jobs = (t_job *)malloc(sizeof(t_job) * a->n_of_philos);
	if (!*jobs)
		return (0);
	*workers = (pthread_t *)malloc(sizeof(pthread_t) * a->n_of_philos);
	if (!*workers)
	{
		free(*jobs);
		*jobs = NULL;
		return (0);
	}
	return (1);
}

static int	init_shared_on_heap(const t_args *a, t_job *j0)
{
	j0->stop = (int *)malloc(sizeof(int));
	j0->last_meal = (long *)malloc(sizeof(long) * a->n_of_philos);
	j0->meals = (int *)malloc(sizeof(int) * a->n_of_philos);
	j0->meal_mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	j0->stop_mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	j0->print_mtx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	j0->forks = NULL;
	if (!j0->stop || !j0->last_meal || !j0->meals
		|| !j0->meal_mtx || !j0->stop_mtx || !j0->print_mtx)
		return (0);
	*(j0->stop) = 0;
	if (pthread_mutex_init(j0->meal_mtx, NULL) != 0)
		return (0);
	if (pthread_mutex_init(j0->stop_mtx, NULL) != 0)
		return (0);
	if (pthread_mutex_init(j0->print_mtx, NULL) != 0)
		return (0);
	if (!forks_init(&j0->forks, a->n_of_philos))
		return (0);
	j0->n_total = a->n_of_philos;
	return (1);
}

static int	start_threads(t_job *jobs, pthread_t *workers
, int n, pthread_t *mon)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pthread_create(&workers[i], NULL, &worker_loop, &jobs[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_create(mon, NULL, &monitor_loop, (void *)&jobs[0]) != 0)
		return (0);
	return (1);
}

static void	join_workers(pthread_t *workers, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join(workers[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_args		a;
	t_job		*jobs;
	pthread_t	*workers;
	pthread_t	mon;
	int			ok;

	if (!check_args(argc, argv, &a))
		return (write(2, "Error\n", 6), 1);
	if (!alloc_jobs_threads(&a, &jobs, &workers))
		return (write(2, "Error\n", 6), 1);
	if (!init_shared_on_heap(&a, &jobs[0]))
		return (free(workers), free(jobs), write(2, "Error\n", 6), 1);
	build_jobs(jobs, &a);
	ok = start_threads(jobs, workers, a.n_of_philos, &mon);
	if (!ok)
		return (stop_set(jobs[0].stop, jobs[0].stop_mtx, 1)
			, cleanup(jobs, workers), write(2, "Error\n", 6), 1);
	pthread_join(mon, NULL);
	stop_set(jobs[0].stop, jobs[0].stop_mtx, 1);
	join_workers(workers, a.n_of_philos);
	cleanup(jobs, workers);
	return (0);
}
