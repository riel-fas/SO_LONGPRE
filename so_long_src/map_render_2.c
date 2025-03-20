/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:17:55 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/20 12:21:33 by riel-fas         ###   ########.fr       */
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
			mlx_image_to_window(game->mlx, game->floor_img,
				x * TILE_SIZE, y * TILE_SIZE);
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
			render_map_elements(game, x, y);
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
