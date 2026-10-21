/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:15:36 by dzotti            #+#    #+#             */
/*   Updated: 2025/09/23 13:15:36 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_job *jobs, pthread_t *workers)
{
	forks_destroy(jobs[0].forks, jobs[0].n_total);
	pthread_mutex_destroy(jobs[0].meal_mtx);
	pthread_mutex_destroy(jobs[0].stop_mtx);
	pthread_mutex_destroy(jobs[0].print_mtx);
	free(jobs[0].meal_mtx);
	free(jobs[0].stop_mtx);
	free(jobs[0].print_mtx);
	free(jobs[0].last_meal);
	free(jobs[0].meals);
	free(jobs[0].stop);
	free(workers);
	free(jobs);
}
