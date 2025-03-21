/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:13:05 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/20 11:25:18 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	process_line(t_game *game, char *line, int x)
{
	int	y;

	y = 0;
	while (line[y] && line[y] != '\n' && y < game->map.width)
	{
		game->map.grid[x][y] = line[y];
		y++;
	}
	while (y < game->map.width)
		game->map.grid[x][y++] = ' ';
	game->map.grid[x][y] = '\0';
	return (1);
}

static int	read_map_lines(t_game *game, int fd)
{
	int		x;
	char	*line;

	x = 0;
	line = get_next_line(fd);
	while (line != NULL && x < game->map.height)
	{
		process_line(game, line, x);
		free(line);
		x++;
		line = get_next_line(fd);
	}
	return (x);
}

int	read_map_content(t_game *game, char *map_path)
{
	int	fd;
	int	x;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	x = read_map_lines(game, fd);
	close(fd);
	x = game->map.height;
	return (x);
}
