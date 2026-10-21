/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:37:37 by dzotti            #+#    #+#             */
/*   Updated: 2025/07/14 14:37:37 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <signal.h>

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(300);
		i--;
	}
}

void	valid_input(int argc, char **argv, int *pid)
{
	if (argc != 3)
	{
		ft_printf("ERROR: Gebruik ./client [PID] [MESSAGE]\n");
		exit(EXIT_FAILURE);
	}
	*pid = ft_atoi(argv[1]);
	if (*pid <= 0)
	{
		ft_printf("ERROR: Ongeldige PID\n");
		exit(EXIT_FAILURE);
	}
	if (kill(*pid, 0) == -1)
	{
		ft_printf("ERROR: Proces met PID %d bestaat niet\n", *pid);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;
	int		i;

	valid_input(argc, argv, &pid);
	i = 0;
	message = argv[2];
	while (message[i])
	{
		send_char(message[i], pid);
		i++;
	}
	send_char('\0', pid);
	return (0);
}
