/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:51:52 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/21 15:11:27 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**allocate_temp_map(t_game *game)
{
	char	**temp_map;
	int		i;

	temp_map = malloc(sizeof(char *) * (game->map.height + 1));
	if (!temp_map)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		temp_map[i] = malloc(sizeof(char) * (game->map.width + 1));
		if (!temp_map[i])
		{
			while (--i >= 0)
				free(temp_map[i]);
			free(temp_map);
			return (NULL);
		}
		i++;
	}
	temp_map[game->map.height] = NULL;
	return (temp_map);
}

void	copy_map(t_game *game, char **temp_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j <= game->map.width)
		{
			temp_map[i][j] = game->map.grid[i][j];
			j++;
		}
		i++;
	}
}

char	**create_temp_map(t_game *game)
{
	char	**temp_map;

	temp_map = allocate_temp_map(game);
	if (!temp_map)
		return (NULL);
	copy_map(game, temp_map);
	return (temp_map);
}

int	check_path(t_game *game)
{
	char	**temp_map;
	int		count;
	int		expected;
	int		i;

	temp_map = create_temp_map(game);
	if (!temp_map)
		return (0);
	count = 0;
	expected = game->map.collectibles + game->map.exit;
	flood_fill(temp_map, game->map.player_x, game->map.player_y, &count);
	i = 0;
	while (i < game->map.height)
		free(temp_map[i++]);
	free(temp_map);
	return (count == expected);
}
