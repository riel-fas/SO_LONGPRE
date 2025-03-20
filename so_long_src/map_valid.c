/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:44:18 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/20 12:55:09 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_element(t_game *game, int i, int j)
{
	if (game->map.grid[i][j] == 'P')
	{
		game->map.player++;
		game->map.player_x = j;
		game->map.player_y = i;
	}
	else if (game->map.grid[i][j] == 'E')
		game->map.exit++;
	else if (game->map.grid[i][j] == 'C')
		game->map.collectibles++;
}

static int	check_characters(t_game *game)
{
	int	i;
	int	j;
	int	valid;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width && game->map.grid[i][j])
		{
			count_element(game, i, j);
			if (game->map.grid[i][j] != 'P' && game->map.grid[i][j] != 'E'
				&& game->map.grid[i][j] != 'C' && game->map.grid[i][j] != '0'
				&& game->map.grid[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	valid = (game->map.player == 1 && game->map.exit == 1);
	return (valid && game->map.collectibles >= 1);
}

static int	check_walls(t_game *game)
{
	int	i;
	int	j;
	int	is_border;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width && game->map.grid[i][j])
		{
			is_border = (i == 0 || i == game->map.height - 1);
			is_border = is_border || (j == 0 || j == game->map.width - 1);
			if (is_border && game->map.grid[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(char **map, int x, int y, int *count)
{
	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0')
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		(*count)++;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, count);
	flood_fill(map, x - 1, y, count);
	flood_fill(map, x, y + 1, count);
	flood_fill(map, x, y - 1, count);
}

int	validate_map(t_game *game)
{
	if (!check_characters(game))
	{
		write(2, "Error\nInvalid map characters or missing elements\n", 49);
		return (0);
	}
	if (!check_walls(game))
	{
		write(2, "Error\nMap must be surrounded by walls\n", 38);
		return (0);
	}
	if (!check_path(game))
	{
		write(2, "Error\nInvalid path in map\n", 26);
		return (0);
	}
	return (1);
}
