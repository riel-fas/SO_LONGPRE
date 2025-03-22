/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:38:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/22 15:17:27 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map.width || new_y < 0
		|| new_y >= game->map.height || game->map.grid[new_y][new_x] == '1')
		return (0);
	return (1);
}

static int	handle_tile(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->map.collected++;
		game->map.grid[new_y][new_x] = '0';
		update_render_map(game);
	}
	else if (game->map.grid[new_y][new_x] == 'E')
	{
		if (game->map.collected == game->map.collectibles)
		{
			ft_printf("You win! Moves: %d\n", game->moves + 1);
			mlx_close_window(game->mlx);
			return (0);
		}
		else
		{
			write(1, "Collect all collectibles before exiting!\n", 41);
			return (0);
		}
	}
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_x + dx;
	new_y = game->map.player_y + dy;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	if (!handle_tile(game, new_x, new_y))
		return ;
	game->map.grid[game->map.player_y][game->map.player_x] = '0';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->map.grid[new_y][new_x] = 'P';
	game->moves++;
	update_render_map(game);
	ft_printf("Moves: %d\n", game->moves);
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(game, 0, -1);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(game, 0, 1);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player(game, -1, 0);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player(game, 1, 0);
		else if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
	}
}
