/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:18:36 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/18 15:00:08 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "../MLX42/include/MLX42/MLX42.h"
// # include "/home/riad/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include <stdio.h>
#define TILE_SIZE 64
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		collected;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
}		t_map;

// typedef struct s_game
// {
//     mlx_t       *mlx;           // MLX42 window
//     mlx_image_t *player_img;    // Player sprite
//     mlx_image_t *wall_img;      // Wall sprite
//     mlx_image_t *collectible_img; // Collectible sprite
//     mlx_image_t *exit_img;      // Exit sprite
//     mlx_image_t *floor_img;     // Floor sprite
//     t_map       map;            // Map data
//     int         moves;          // Move counter
// } t_game;

typedef struct s_game
{
    mlx_t       *mlx;           // MLX42 window
    mlx_image_t *player_img;    // Player sprite
    mlx_image_t *wall_img;      // Wall sprite
    mlx_image_t *collectible_img; // Collectible sprite
    mlx_image_t *exit_img;      // Exit sprite
    mlx_image_t *floor_img;     // Floor sprite

    // Image instances arrays
    mlx_instance_t *wall_instances;
    mlx_instance_t *floor_instances;
    mlx_instance_t *collectible_instances;
    mlx_instance_t *exit_instances;
    int player_instance;        // Index of player instance

    t_map       map;            // Map data
    int         moves;          // Move counter

    // Add counters for instances
    int wall_count;
    int collectible_count;
    int exit_count;
} t_game;


int		parse_map(t_game *game, char *map_path);
int		validate_map(t_game *game);

void move_player(t_game *game, int dx, int dy);
void handle_keypress(mlx_key_data_t keydata, void *param);
void render_map(t_game *game);
void init_game(t_game *game);
void update_render_map(t_game *game);


void	free_game(t_game *game);
void	exit_with_error(char *message);
int		handle_window_close(t_game *game);


void load_assets(t_game *game);
void game_loop(void *param);




#endif
