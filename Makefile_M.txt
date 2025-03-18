NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror

# Paths for MLX42
LIBMLX	= /Users/riel-fas/MLX42
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
SRCS	= main.c map.c player_movement.c
OBJS	= ${SRCS:.c=.o}

# get_next_line
GNL = Get_Next_Line/get_next_line.c Get_Next_Line/get_next_line_utils.c
OGNL = ${GNL:.c=.o}

# Combine all object files
ALL_OBJS = $(OBJS) $(OGNL)

all: $(NAME)

$(NAME): $(ALL_OBJS)
		$(CC) $(ALL_OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
		rm -rf $(OBJS) $(OGNL)

fclean: clean
		rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
