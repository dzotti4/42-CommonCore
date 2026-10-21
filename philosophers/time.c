/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:31:51 by dzotti            #+#    #+#             */
/*   Updated: 2025/08/27 19:31:51 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	now_ms(void)
{
	struct timeval	tv;
	long			n;

	gettimeofday(&tv, NULL);
	n = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
	return (n);
}

void	ms_sleep(long ms)
{
	long	end;
	long	rem;

	if (ms <= 0)
		return ;
	end = now_ms() + ms;
	rem = end - now_ms();
	while (rem > 1)
	{
		usleep(1000);
		rem = end - now_ms();
	}
	while (now_ms() < end)
		usleep(100);
}

void	log_state(long start_ms, int id, const char *msg)
{
	printf("%ld %d %s\n", now_ms() - start_ms, id, msg);
}
