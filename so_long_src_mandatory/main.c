/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:24:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/22 09:34:57 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init(game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long", false);
	if (!game->mlx)
		exit_with_error("ERROR: Failed to initialize MLX.");
	game->wall_count = 0;
	game->collectible_count = 0;
	game->exit_count = 0;
	load_assets(game);
	game->moves = 0;
	render_map(game);
	mlx_loop_hook(game->mlx, game_loop, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(1, "Usage: av[0] map_file.ber\n", 26);
		return (1);
	}
	if (!parse_map(&game, argv[1]))
	{
		write(1, "Map parsing failed\n", 19);
		return (1);
	}
	init_game(&game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
