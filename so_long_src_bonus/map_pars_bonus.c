/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:37:55 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/21 15:11:34 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	map_dimensions(t_game *game, char *map_path)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_with_error("ERROR OPENING MAP FILE");
	game->map.width = 0;
	game->map.height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		width = 0;
		while (line[width] && line[width] != '\n')
			width++;
		if (width > game->map.width)
			game->map.width = width;
		game->map.height++;
		free(line);
		line = get_next_line(fd);
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

static int	init_map_data(t_game *game)
{
	game->map.collectibles = 0;
	game->map.collected = 0;
	game->map.exit = 0;
	game->map.player = 0;
	return (1);
}

static int	handle_map_errors(t_game *game, int error_code)
{
	if (error_code == 1)
		write(2, "Error\nFailed to read map file\n", 30);
	else if (error_code == 2)
		write(2, "Error\nMemory allocation failed\n", 31);
	else if (error_code == 3)
		write(2, "Error\nFailed to read map content\n", 33);
	if (error_code == 2 || error_code == 3)
		free_game(game);
	return (0);
}

int	parse_map(t_game *game, char *map_path)
{
	if (!init_map_data(game))
		return (0);
	if (!map_dimensions(game, map_path))
		return (handle_map_errors(game, 1));
	if (!map_alloc(game))
		return (handle_map_errors(game, 2));
	if (!read_map_content(game, map_path))
		return (handle_map_errors(game, 3));
	if (!validate_map(game))
	{
		free_game(game);
		return (0);
	}
	return (1);
}
