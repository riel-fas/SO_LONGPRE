/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:33:11 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/20 09:27:37 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_assets(t_game *game)
{
	mlx_texture_t *texture;
	texture = mlx_load_png("textures/player/player.png");
	if (!texture)
		exit_with_error("ERROR: Failed to load player sprite.");
	game->player_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("textures/1/wall.png");
	if (!texture)
		exit_with_error("ERROR: Failed to load wall sprite.");
	game->wall_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	game->wall_count = 0;
	texture = mlx_load_png("textures/collectibles/collectible.png");
	if (!texture)
		exit_with_error("ERROR: Failed to load collectible sprite.");
	game->collectible_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	game->collectible_count = 0;
	texture = mlx_load_png("textures/exit/exit.png");
	if (!texture)
		exit_with_error("ERROR: Failed to load exit sprite.");
	game->exit_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	game->exit_count = 0;
	texture = mlx_load_png("textures/0/floor.png");
	if (!texture)
		exit_with_error("ERROR: Failed to load floor sprite.");
	game->floor_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(game->player_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->wall_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->collectible_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->exit_img, TILE_SIZE, TILE_SIZE);
	mlx_resize_image(game->floor_img, TILE_SIZE, TILE_SIZE);
}
