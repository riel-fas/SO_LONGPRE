/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:38:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/18 15:00:44 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->map.player_x + dx;
    int new_y = game->map.player_y + dy;

    // Check if the new position is within the map boundaries
    if (new_x < 0 || new_x >= game->map.width || new_y < 0 || new_y >= game->map.height)
        return; // Out of bounds

    // Check if the new position is a wall
    if (game->map.grid[new_y][new_x] == '1')
        return; // Wall collision

    // Handle collectibles
    if (game->map.grid[new_y][new_x] == 'C')
    {
        game->map.collected++; // Increment collected count
        game->map.grid[new_y][new_x] = '0'; // Remove collectible from the map
    }

    // Handle exit
    if (game->map.grid[new_y][new_x] == 'E')
    {
        if (game->map.collected == game->map.collectibles)
        {
            printf("You win! Moves: %d\n", game->moves + 1);
            mlx_close_window(game->mlx); // Close the game window
            return;
        }
        else
        {
            printf("Collect all collectibles before exiting!\n");
            return;
        }
    }

    // Update player position
    game->map.grid[game->map.player_y][game->map.player_x] = '0'; // Clear old position
    game->map.player_x = new_x;
    game->map.player_y = new_y;
    game->map.grid[new_y][new_x] = 'P'; // Set new position

    // Increment move counter
    game->moves++;

    // Update the rendering (much more efficient than redrawing everything)
    update_render_map(game);

    // Debug print
    printf("Player moved to (%d, %d). Moves: %d\n", new_x, new_y, game->moves);
}

void handle_keypress(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    // Check if the key is pressed (not released or repeated)
    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
        // Move player based on key pressed
        if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
            move_player(game, 0, -1); // Move up
        else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
            move_player(game, 0, 1);  // Move down
        else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
            move_player(game, -1, 0); // Move left
        else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
            move_player(game, 1, 0);  // Move right
        else if (keydata.key == MLX_KEY_ESCAPE)
            mlx_close_window(game->mlx); // Close the window
    }
}

void render_map(t_game *game)
{
    int x, y;
    // int wall_count = 0;
    // int collectible_count = 0;
    // int exit_count = 0;

    // First, add all floor tiles to window
    for (y = 0; y < game->map.height; y++) {
        for (x = 0; x < game->map.width; x++) {
            mlx_image_to_window(game->mlx, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
        }
    }

    // Then add wall, collectible, exit and player tiles
    for (y = 0; y < game->map.height; y++) {
        for (x = 0; x < game->map.width; x++) {
            if (game->map.grid[y][x] == '1') {
                mlx_image_to_window(game->mlx, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
                game->wall_count++;
            } else if (game->map.grid[y][x] == 'C') {
                mlx_image_to_window(game->mlx, game->collectible_img, x * TILE_SIZE, y * TILE_SIZE);
                game->collectible_count++;
            } else if (game->map.grid[y][x] == 'E') {
                mlx_image_to_window(game->mlx, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
                game->exit_count++;
            } else if (game->map.grid[y][x] == 'P') {
                game->player_instance = mlx_image_to_window(game->mlx, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
            }
        }
    }

    printf("Map initialized with %d walls, %d collectibles, %d exits\n",
           game->wall_count, game->collectible_count, game->exit_count);
}

void update_render_map(t_game *game)
{
    int x, y;
    int collectible_idx = 0;

    // Only update what's needed - player and collectibles

    // Update player position
    game->player_img->instances[0].x = game->map.player_x * TILE_SIZE;
    game->player_img->instances[0].y = game->map.player_y * TILE_SIZE;

    // Update collectibles - hide collected ones
    collectible_idx = 0;
    for (y = 0; y < game->map.height; y++) {
        for (x = 0; x < game->map.width; x++) {
            if (game->map.grid[y][x] == 'C' && collectible_idx < game->collectible_count) {
                game->collectible_img->instances[collectible_idx].enabled = true;
                collectible_idx++;
            } else if (game->map.grid[y][x] == '0' && collectible_idx < game->collectible_count) {
                // Check if this was previously a collectible location
                if (game->collectible_img->instances[collectible_idx].x == x * TILE_SIZE &&
                    game->collectible_img->instances[collectible_idx].y == y * TILE_SIZE) {
                    game->collectible_img->instances[collectible_idx].enabled = false;
                    collectible_idx++;
                }
            }
        }
    }
}

void game_loop(void *param)
{
    t_game *game = (t_game *)param;
    static int last_move_time = 0;
    int current_time;

    // Get current time (a simple frame counter will do)
    current_time = mlx_get_time() * 1000; // Convert to milliseconds

    // Limit movement to avoid too fast repeated movements
    if (current_time - last_move_time < 100) // 100ms delay between moves
        return;

    // Handle key inputs - only process one at a time with priority
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) { // Exit game
        mlx_close_window(game->mlx);
        return;
    }

    if (mlx_is_key_down(game->mlx, MLX_KEY_W)) { // Move up
        move_player(game, 0, -1);
        last_move_time = current_time;
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_S)) { // Move down
        move_player(game, 0, 1);
        last_move_time = current_time;
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_A)) { // Move left
        move_player(game, -1, 0);
        last_move_time = current_time;
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_D)) { // Move right
        move_player(game, 1, 0);
        last_move_time = current_time;
    }
}
