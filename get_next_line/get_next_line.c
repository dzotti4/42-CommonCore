/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:06:23 by dzotti            #+#    #+#             */
/*   Updated: 2025/05/14 11:06:23 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*failed_dup(char **stash, char *line)
{
	free(*stash);
	*stash = NULL;
	free(line);
	return (NULL);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*rest;
	int		i;

	if (!*stash || **stash == '\0')
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	line = ft_substr(*stash, 0, i);
	if (!line)
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	rest = ft_strdup(*stash + i);
	if (!rest)
		return (failed_dup(stash, line));
	free(*stash);
	*stash = rest;
	return (line);
}

static int	read_and_store(int fd, char **stash)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr(*stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (bytes_read);
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(*stash, buf);
		if (!tmp)
		{
			free(*stash);
			*stash = NULL;
			return (-1);
		}
		free(*stash);
		*stash = tmp;
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = read_and_store(fd, &stash);
	if (bytes < 0 || (bytes == 0 && (!stash || *stash == '\0')))
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(&stash);
	return (line);
}
