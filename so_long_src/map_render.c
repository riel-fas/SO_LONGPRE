/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:22:25 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/20 08:37:24 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floor(t_game *game)
{
    int	x;
    int	y;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            mlx_image_to_window(game->mlx, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

static void	render_elements(t_game *game)
{
    int	x;
    int	y;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (game->map.grid[y][x] == '1')
                mlx_image_to_window(game->mlx, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.grid[y][x] == 'C')
                mlx_image_to_window(game->mlx, game->collectible_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.grid[y][x] == 'E')
                mlx_image_to_window(game->mlx, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map.grid[y][x] == 'P')
                game->player_instance = mlx_image_to_window(game->mlx, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

void	render_map(t_game *game)
{
    render_floor(game);
    render_elements(game);
}


static void	update_player_position(t_game *game)
{
    game->player_img->instances[0].x = game->map.player_x * TILE_SIZE;
    game->player_img->instances[0].y = game->map.player_y * TILE_SIZE;
}

static void update_collectibles(t_game *game)
{
    int x;
    int y;
    size_t instance_idx = 0;

    while (instance_idx < game->collectible_img->count)
    {
        game->collectible_img->instances[instance_idx].enabled = false;
		instance_idx++;
    }
    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            if (game->map.grid[y][x] == 'C')
            {
                // Find an available instance to show the collectible
                instance_idx = 0;
				while (instance_idx < game->collectible_img->count)
                {
                    if (!game->collectible_img->instances[instance_idx].enabled)
                    {
                        game->collectible_img->instances[instance_idx].x = x * TILE_SIZE;
                        game->collectible_img->instances[instance_idx].y = y * TILE_SIZE;
                        game->collectible_img->instances[instance_idx].enabled = true;
                        break;
                    }
					instance_idx++;
                }
            }
            x++;
        }
        y++;
    }
}

void	update_render_map(t_game *game)
{
	update_player_position(game);
	update_collectibles(game);
}
