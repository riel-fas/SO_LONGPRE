/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:37:55 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/17 12:19:20 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_dimensions(t_game *game, char *map_path)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		write(2, "ERROR OPENING MAP FILE\n", 23);
		exit(EXIT_FAILURE);
	}
	game->map.width = 0;
	game->map.height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		width = 0;
		while (line[width] && line[width] != '\n')
			width++;
		if (width > game->map.width)
			game->map.width = width;
		game->map.height++;
		free(line);
	}
	close (fd);
	if (game->map.width <= 0 || game->map.height <= 0)
		return (0);
	return (1);
}

static int	map_alloc(t_game *game)
{
	int	x;

	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		return (0);
	x = 0;
	while (x < game->map.height)
	{
		game->map.grid[x] = malloc(sizeof(char) * (game->map.width + 1));
		if (!game->map.grid[x])
		{
			while (--x >= 0)
				free(game->map.grid[x]);
			free(game->map.grid);
			return (0);
		}
		x++;
	}
	game->map.grid[game->map.height] = NULL;
	return (1);
}

static int	read_map_content(t_game *game, char *map_path)
{
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	x = 0;
	while ((line = get_next_line(fd)) != NULL && x < game->map.height)
	{
		y = 0;
		while (line[y] && line[y] != '\n' && y < game->map.width)
		{
			game->map.grid[x][y] = line[y];
			y++;
		}
		while (y < game->map.width)
			game->map.grid[x][y++] = ' ';
		game->map.grid[x][y] = '\0';
		free(line);
		x++;
	}
	close (fd);
	x = game->map.height;
	return (x);
}

int parse_map(t_game *game, char *map_path)
{
	game->map.collectibles = 0;
	game->map.collected = 0;
	game->map.exit = 0;
	game->map.player = 0;
	if (!map_dimensions(game, map_path))
	{
		write(2, "Error\nFailed to read map file\n", 30);
		return (0);
	}
	if (!map_alloc(game))
	{
		write(2, "Error\nMemory allocation failed\n", 31);
		return (0);
	}
	if (!read_map_content(game, map_path))
	{
		write(2, "Error\nFailed to read map content\n", 33);
		free_game(game); // You'll need to implement this function
		return (0);
	}
	if (!validate_map(game))
	{
		free_game(game);
		return (0);
	}
	return (1);
}
