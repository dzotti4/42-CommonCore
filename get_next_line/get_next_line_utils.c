/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzotti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:06:44 by dzotti            #+#    #+#             */
/*   Updated: 2025/05/14 11:06:44 by dzotti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	if (!s)
		return (NULL);
	copy = malloc(ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*copy;

	if (!s1 && !s2)
		return (ft_strdup(""));
	copy = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		copy [i + j] = s2[j];
		j++;
	}
	copy[i + j] = '\0';
	return (copy);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len + start > s_len)
		len = s_len - start;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		copy[i] = s[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
