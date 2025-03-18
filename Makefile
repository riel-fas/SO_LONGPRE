NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror

# Paths for MLX42
LIBMLX	= /Users/riel-fas/Desktop/SSSLLL/MLX42
MLX_INCLUDE	= $(LIBMLX)/include/MLX42
MLX_LIB	= $(LIBMLX)/build/libmlx42.a

# Paths for GLFW
GLFW_INCLUDE = /Users/riel-fas/.brew/include
GLFW_LIB = /Users/riel-fas/.brew/lib

# Include paths
HEADERS	= -I ./include -I $(MLX_INCLUDE) -I $(GLFW_INCLUDE)

# Libraries
LIBS = $(MLX_LIB) -L $(GLFW_LIB) -lglfw -ldl -pthread -lm

# Source files
SRCS	=	so_long_src/main.c \
            so_long_src/map_pars.c \
			so_long_src/key_press.c \
			so_long_src/textures_in.c \
			so_long_src/map_valid.c \
			so_long_src/errors_handl.c \
            libft/get_next_line/get_next_line.c \
            libft/get_next_line/get_next_line_utils.c
OBJS	= ${SRCS:.c=.o}


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME) $(CFLAGS)

$(LIBFT) :
		make -C libft

%.o: %.c
		$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

clean:
		rm -rf $(OBJS)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re: clean all

.PHONY: all clean fclean re


# NAME	= so_long
# CC		= cc -g
# CFLAGS	= -Wextra -Wall -Werror -fsanitize=address

# LIBMLX	= /home/riad/MLX42
# MLX_INCLUDE	= $(LIBMLX)/include/MLX42
# MLX_LIB	= $(LIBMLX)/build/libmlx42.a

# GLFW_INCLUDE = /home/linuxbrew/.linuxbrew/include
# GLFW_LIB = /home/linuxbrew/.linuxbrew/lib

# HEADERS	= -I ./include -I $(MLX_INCLUDE) -I $(GLFW_INCLUDE)

# LIBFT	= libft/libft.a

# LIBS = $(MLX_LIB) -L $(GLFW_LIB) -lglfw -ldl -pthread -lm -fsanitize=address

# SRCS	=	so_long_src/main.c \
#             so_long_src/map_pars.c \
# 			so_long_src/key_press.c \
# 			so_long_src/textures_in.c \
# 			so_long_src/map_valid.c \
# 			so_long_src/errors_handl.c \
#             libft/get_next_line/get_next_line.c \
#             libft/get_next_line/get_next_line_utils.c

# OBJS	= ${SRCS:.c=.o}

# all: $(NAME)

# $(NAME): $(OBJS) $(LIBFT)
# 		$(CC) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME) $(CFLAGS)

# $(LIBFT) :
# 		make -C libft

# %.o: %.c
# 		$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

# clean:
# 		rm -rf $(OBJS)
# 		make clean -C libft

# fclean: clean
# 		rm -rf $(NAME)
# 		make fclean -C libft

# re: clean all

# .PHONY: all clean fclean re


# SRCS	=	so_long_src/main.c \
#             so_long_src/map_pars.c \
# 			so_long_src/map_valid.c \
# 			so_long_src/errors_handl.c \
#             libft/get_next_line/get_next_line.c \
#             libft/get_next_line/get_next_line_utils.c
