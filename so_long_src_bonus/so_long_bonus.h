/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:18:36 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/22 15:10:29 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "/Users/riel-fas/MLX42/include/MLX42/MLX42.h"
// #include "/home/riad/MLX42/include/MLX42/MLX42.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define TILE_SIZE 64
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}		t_img;

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
	int				collectibles;
	int				collected;
	int				exit;
	int				player;
	int				player_x;
	int				player_y;
}		t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*player_img;
	mlx_image_t		*enemy_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*collectible_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*floor_img;
	mlx_instance_t	*wall_instances;
	mlx_instance_t	*floor_instances;
	mlx_instance_t	*collectible_instances;
	mlx_instance_t	*exit_instances;
	int				player_instance;
	t_map			map;
	int				moves;
	int				wall_count;
	int				collectible_count;
	int				exit_count;

	mlx_image_t *move_count_img;

    mlx_image_t *enemy_frames[7]; // Array of enemy frames
    int num_enemy_frames;         // Number of enemy frames
    int current_enemy_frame;      // Current enemy frame index


}		t_game;


void init_move_count_text(t_game *game);
char	*ft_strjoin_bonus(char *s1, char *s2);


int			parse_map(t_game *game, char *map_path);
int			validate_map(t_game *game);
void		move_player(t_game *game, int dx, int dy);
void		handle_keypress(mlx_key_data_t keydata, void *param);
void		render_map(t_game *game);
void		init_game(t_game *game);
void		update_render_map(t_game *game);
void		free_game(t_game *game);
void		exit_with_error(char *message);
int			handle_window_close(t_game *game);
void		load_assets(t_game *game);
void		game_loop(void *param);
void		handle_movement(t_game *game, int current, int *last_move);
int			read_map_content(t_game *game, char *map_path);
void		render_map_elements(t_game *game, int x, int y);
char		**allocate_temp_map(t_game *game);
void		copy_map(t_game *game, char **temp_map);
char		**create_temp_map(t_game *game);
int			check_path(t_game *game);
void		flood_fill(char **map, int x, int y, int *count);

#endif
