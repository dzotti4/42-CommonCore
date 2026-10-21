/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:07:35 by dzotti            #+#    #+#             */
/*   Updated: 2025/07/14 12:07:35 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "ft_printf.h"

void	signal_handler(int signum)
{
	static int	bit_index = 0;
	static char	character = 0;

	if (signum == SIGUSR2)
		character |= (1 << (7 - bit_index));
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &character, 1);
		if (character == '\0')
			write(1, "\n", 1);
		bit_index = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t	p;

	p = getpid();
	ft_printf("Process ID: %d\n", p);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
