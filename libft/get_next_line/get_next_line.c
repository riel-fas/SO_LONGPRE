/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:30:39 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/22 15:08:06 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freeline(char *stash)
{
	char	*line;
	int		x;

	x = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[x] && stash[x] != '\n')
		x++;
	if (!stash[x] || stash[x + 1] == '\0')
	{
		free(stash);
		return (NULL);
	}
	line = ft_substr(stash, x + 1, ft_strlen(stash) - x - 1);
	free(stash);
	if (line && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*read_from_file(int fd, char *stash, char *buffer)
{
	char	*tmp;
	int		buffer_read;

	while (1)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read <= 0)
			break ;
		buffer[buffer_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin_2(tmp, buffer);
		free(tmp);
		if (!stash)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (buffer_read < 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

char	*get_line_from_stash(char *stash)
{
	char	*line;
	int		x;

	x = 0;
	while (stash[x] && stash[x] != '\n')
		x++;
	line = ft_substr(stash, 0, x + (stash[x] == '\n'));
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stash = read_from_file(fd, stash, buffer);
	free(buffer);
	if (!stash)
		return (NULL);
	line = get_line_from_stash(stash);
	if (!line)
		return (NULL);
	stash = ft_freeline(stash);
	return (line);
}
