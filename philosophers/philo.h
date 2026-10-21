/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:14 by dzotti            #+#    #+#             */
/*   Updated: 2025/08/27 19:17:14 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>

// invoer/argumenten
typedef struct s_args
{
	int				n_of_philos;
	int				n_times_must_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
}	t_args;
// mapping per stoel
typedef struct s_philo
{
	int	id;
	int	left;
	int	right;
}	t_philo;

typedef struct s_job
{
	int				id;
	int				left;
	int				right;
	// timing
	long			start_ms;
	// t_args
	int				t_eat;
	int				t_sleep;
	int				time_to_die;
	int				must_eat;
	int				n_total;
	// gedeelde array en stops
	int				*stop;
	long			*last_meal;
	int				*meals;
	// synchronisatie
	pthread_mutex_t	*meal_mtx;
	pthread_mutex_t	*stop_mtx;
	pthread_mutex_t	*print_mtx;
	pthread_mutex_t	*forks;
}	t_job;

int		is_number(const char *s);
int		ft_atoi(const char *s);
int		check_args(int argc, char **argv, t_args *p);

long	now_ms(void);
void	ms_sleep(long ms);
void	log_state(long start_ms, int id, const char *msg);

int		forks_init(pthread_mutex_t **forks, int n);
void	forks_destroy(pthread_mutex_t *forks, int n);

void	action_safe_log(t_job *a, const char *msg);
void	action_take_forks(t_job *a);
void	action_eat_and_release(t_job *a);
void	action_sleep_and_think(t_job *a);

int		stop_get(int *stop, pthread_mutex_t *stop_mtx);
void	stop_set(int *stop, pthread_mutex_t *stop_mtx, int i);
void	*worker_loop(void *ptr);

void	*monitor_loop(void *ptr);

void	cleanup(t_job *jobs, pthread_t *workers);

void	build_jobs(t_job *jobs, const t_args *a);

#endif
