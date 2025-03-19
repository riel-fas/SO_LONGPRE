/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:33:11 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/19 14:29:13 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_assets(t_game *game)
{
	mlx_texture_t *texture;
    // int max_tiles = game->map.width * game->map.height;

    // Load player sprite
	texture = mlx_load_png("textures/player/golden_death.png");
	if (!texture)
		exit_with_error("ERROR: Failed to load player sprite.");
	game->player_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);

    // Load wall sprite - create with enough instances
	texture = mlx_load_png("textures/1/mainfloorx64.png");
	if (!texture)
		exit_with_error("ERROR: Failed to load wall sprite.");
	game->wall_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	game->wall_count = 0;

    // Load collectible sprite
	texture = mlx_load_png("textures/collectibles/green_crystal_0000.png");
	if (!texture)
		exit_with_error("ERROR: Failed to load collectible sprite.");
	game->collectible_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	game->collectible_count = 0;

    // Load exit sprite
	texture = mlx_load_png("textures/exit/floorx643333.png");
	if (!texture)
		exit_with_error("ERROR: Failed to load exit sprite.");
	game->exit_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	game->exit_count = 0;

    // Load floor sprite
	texture = mlx_load_png("textures/0/mainlevbuildx64.png");
	if (!texture)
		exit_with_error("ERROR: Failed to load floor sprite.");
	game->floor_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);

    // Resize all images for better memory usage (optional)
	mlx_resize_image(game->player_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->wall_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->collectible_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->exit_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->floor_img, TILE_SIZE, TILE_SIZE);
}
