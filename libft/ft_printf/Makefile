NAME = libftprintf.a

SRCS = ft_printf.c ft_char.c ft_nbr.c ft_str.c ft_hexa.c ft_unbr.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean
