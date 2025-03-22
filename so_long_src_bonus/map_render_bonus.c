/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:22:25 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/22 16:00:46 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_map_elements(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == '1')
		mlx_image_to_window(game->mlx, game->wall_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.grid[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->collectible_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.grid[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->exit_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.grid[y][x] == 'P')
		game->player_instance = mlx_image_to_window(game->mlx,
				game->player_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.grid[y][x] == 'X')
		mlx_image_to_window(game->mlx, game->enemy_img,
			x * TILE_SIZE, y * TILE_SIZE);
}

static void	place_collectible(t_game *game, int x, int y)
{
	size_t	instance_idx;

	instance_idx = 0;
	while (instance_idx < game->collectible_img->count)
	{
		if (!game->collectible_img->instances[instance_idx].enabled)
		{
			game->collectible_img->instances[instance_idx].x = x * TILE_SIZE;
			game->collectible_img->instances[instance_idx].y = y * TILE_SIZE;
			game->collectible_img->instances[instance_idx].enabled = true;
			break ;
		}
		instance_idx++;
	}
}

static void	update_collectibles(t_game *game)
{
	int		x;
	int		y;
	size_t	idx;

	idx = 0;
	while (idx < game->collectible_img->count)
	{
		game->collectible_img->instances[idx].enabled = false;
		idx++;
	}
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'C')
				place_collectible(game, x, y);
			x++;
		}
		y++;
	}
}

void	update_render_map(t_game *game)
{
	game->player_img->instances[0].x = game->map.player_x * TILE_SIZE;
	game->player_img->instances[0].y = game->map.player_y * TILE_SIZE;
	update_collectibles(game);
}
