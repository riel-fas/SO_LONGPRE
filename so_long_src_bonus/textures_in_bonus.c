/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_in_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:33:11 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/21 15:11:14 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_asset(t_game *game, const char *path, mlx_image_t **img,
			int *count)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		exit_with_error("ERROR: Failed to load sprite.");
	*img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	if (count)
		*count = 0;
	mlx_resize_image(*img, TILE_SIZE, TILE_SIZE);
}

void	load_assets(t_game *game)
{
	load_asset(game, "textures/player/player.png", &game->player_img, NULL);
	load_asset(game, "textures/1/wall.png", &game->wall_img, &game->wall_count);
	load_asset(game, "textures/collectibles/collectible.png",
		&game->collectible_img, &game->collectible_count);
	load_asset(game, "textures/exit/exit.png", &game->exit_img,
		&game->exit_count);
	load_asset(game, "textures/0/floor.png", &game->floor_img, NULL);
}
