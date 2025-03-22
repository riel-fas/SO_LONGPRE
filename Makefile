# ##LINUX###########################################

NAME					= so_long
BONUS					= so_long_bonus

CC						= cc -g
CFLAGS					= -Wextra -Wall -Werror

LIBMLX					= /MLX42
MLX_INCLUDE				= $(LIBMLX)/include/MLX42
MLX_LIB					= MLX42/build/libmlx42.a

GLFW_INCLUDE 			= /home/linuxbrew/.linuxbrew/include
GLFW_LIB 				= /home/linuxbrew/.linuxbrew/lib

HEADERS					= -I ./include -I $(MLX_INCLUDE) -I $(GLFW_INCLUDE)
HEADER_FILES			= so_long_src_mandatory/so_long.h
HEADER_FILES_BONUS		= so_long_src_bonus/so_long_bonus.h


LIBFT					= libft/libft.a
FT_PRINTF 				= ft_printf/libftprintf.a

LIBS 					= $(MLX_LIB) -L $(GLFW_LIB) -lglfw -ldl -pthread -lm

SRCS	=	so_long_src_mandatory/main.c \
			so_long_src_mandatory/map_pars.c \
			so_long_src_mandatory/map_pars_2.c \
			so_long_src_mandatory/map_render.c \
			so_long_src_mandatory/map_render_2.c \
			so_long_src_mandatory/key_press.c \
			so_long_src_mandatory/textures_in.c \
			so_long_src_mandatory/map_valid.c \
			so_long_src_mandatory/map_valid_2.c \
			so_long_src_mandatory/errors_handl.c \
			so_long_src_mandatory/game_loop.c \
			libft/get_next_line/get_next_line.c \
			libft/get_next_line/get_next_line_utils.c \
 			ft_printf/libftprintf.a

OBJS	= ${SRCS:.c=.o}

SRCS_BONUS				=	so_long_src_bonus/main_bonus.c \
							so_long_src_bonus/map_pars_bonus.c \
							so_long_src_bonus/map_pars_2_bonus.c \
							so_long_src_bonus/map_render_bonus.c \
							so_long_src_bonus/map_render_2_bonus.c \
							so_long_src_bonus/key_press_bonus.c \
							so_long_src_bonus/textures_in_bonus.c \
							so_long_src_bonus/map_valid_bonus.c \
							so_long_src_bonus/map_valid_2_bonus.c \
							so_long_src_bonus/errors_handl_bonus.c \
							so_long_src_bonus/game_loop_bonus.c \
							libft/get_next_line/get_next_line.c \
							libft/get_next_line/get_next_line_utils.c

OBJS_BONUS				= ${SRCS_BONUS:.c=.o}



all: $(LIBFT) $(FT_PRINTF) $(NAME)

bonus: $(LIBFT) $(FT_PRINTF) $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $(BONUS)

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

%.o: %.c $(HEADER_FILES) $(HEADER_FILES_BONUS)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	rm -rf $(NAME) $(BONUS)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(FT_PRINTF) $(BONUS)


##################Mac##########################################

# NAME					= so_long
# BONUS					= so_long_bonus

# CC						= cc
# CFLAGS					= -Wextra -Wall -Werror

# LIBMLX					= /Users/riel-fas/MLX42
# MLX_INCLUDE				= $(LIBMLX)/include/MLX42
# MLX_LIB					= $(LIBMLX)/build/libmlx42.a

# GLFW_INCLUDE 			= /Users/riel-fas/.brew/include
# GLFW_LIB 				= /Users/riel-fas/.brew/lib

# HEADERS					= -I ./so_long_src_mandatory -I $(MLX_INCLUDE) -I $(GLFW_INCLUDE)
# HEADER_FILES			= so_long_src_mandatory/so_long.h
# HEADER_FILES_BONUS		= so_long_src_bonus/so_long_bonus.h

# LIBFT					= libft/libft.a
# FT_PRINTF				= ft_printf/libftprintf.a

# LIBS					= $(MLX_LIB) $(LIBFT) $(FT_PRINTF) -L $(GLFW_LIB) -lglfw -ldl -pthread -lm

# SRCS					=	so_long_src_mandatory/main.c \
# 							so_long_src_mandatory/map_pars.c \
# 							so_long_src_mandatory/map_pars_2.c \
# 							so_long_src_mandatory/map_render.c \
# 							so_long_src_mandatory/map_render_2.c \
# 							so_long_src_mandatory/key_press.c \
# 							so_long_src_mandatory/textures_in.c \
# 							so_long_src_mandatory/map_valid.c \
# 							so_long_src_mandatory/map_valid_2.c \
# 							so_long_src_mandatory/errors_handl.c \
# 							so_long_src_mandatory/game_loop.c \
# 							libft/get_next_line/get_next_line.c \
# 							libft/get_next_line/get_next_line_utils.c

# OBJS					= ${SRCS:.c=.o}

# SRCS_BONUS				=	so_long_src_bonus/main_bonus.c \
# 							so_long_src_bonus/map_pars_bonus.c \
# 							so_long_src_bonus/map_pars_2_bonus.c \
# 							so_long_src_bonus/map_render_bonus.c \
# 							so_long_src_bonus/map_render_2_bonus.c \
# 							so_long_src_bonus/key_press_bonus.c \
# 							so_long_src_bonus/textures_in_bonus.c \
# 							so_long_src_bonus/map_valid_bonus.c \
# 							so_long_src_bonus/map_valid_2_bonus.c \
# 							so_long_src_bonus/errors_handl_bonus.c \
# 							so_long_src_bonus/game_loop_bonus.c \
# 							libft/get_next_line/get_next_line.c \
# 							libft/get_next_line/get_next_line_utils.c

# OBJS_BONUS				= ${SRCS_BONUS:.c=.o}



# all: $(LIBFT) $(FT_PRINTF) $(NAME)

# bonus: $(LIBFT) $(FT_PRINTF) $(BONUS)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# $(BONUS): $(OBJS_BONUS)
# 	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $(BONUS)

# $(LIBFT):
# 	make -C libft

# $(FT_PRINTF):
# 	make -C ft_printf

# %.o: %.c $(HEADER_FILES) $(HEADER_FILES_BONUS)
# 	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@


# clean:
# 	rm -rf $(OBJS) $(OBJS_BONUS)
# 	make clean -C libft
# 	make clean -C ft_printf

# fclean: clean
# 	rm -rf $(NAME) $(BONUS)
# 	make fclean -C libft
# 	make fclean -C ft_printf

# re: fclean all

# .PHONY: all clean fclean re $(LIBFT) $(FT_PRINTF) $(BONUS)
