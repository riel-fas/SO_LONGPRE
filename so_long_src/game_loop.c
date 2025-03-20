/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:57:26 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/20 11:56:30 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_movement(t_game *game, int current, int *last_move)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		move_player(game, 0, -1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		move_player(game, 0, 1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player(game, -1, 0);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player(game, 1, 0);
	*last_move = current;
}

void	game_loop(void *param)
{
	t_game		*game;
	int			current_time;
	static int	last_move_time = 0;

	game = (t_game *)param;
	current_time = mlx_get_time() * 1000;
	if (current_time - last_move_time < 100)
		return ;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(game->mlx);
		return ;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_A)
		|| mlx_is_key_down(game->mlx, MLX_KEY_D))
		handle_movement(game, current_time, &last_move_time);
}
