# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yousong <yousong@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 03:24:09 by yousong           #+#    #+#              #
#    Updated: 2024/09/04 15:21:00 by yousong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c \
		image.c \
		movement.c \
		map.c \
		path.c \
		free.c \
		so_long_utils.c \
		get_next_line.c \
		get_next_line_utils.c \

OBJS = $(SRCS:%.c=%.o)

LIBFT = libft
LIBFT_LIB = libft.a

FT_PRINTF = ft_printf
FT_PRINTF_LIB = libftprintf.a

AR = ar rc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		make all -C $(LIBFT)/
		make all -C $(FT_PRINTF)/
		$(CC) -o $(NAME) $(OBJS) -Llibft -lft -L$(FT_PRINTF) -lftprintf -Lmlx_linux -lmlx_Linux -L./mlx_linux -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c
		$(CC) $(FLAGS) -c $< -I./ -I$(LIBFT) -I$(FT_PRINTF) -o $@

clean:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)
		make clean -C $(FT_PRINTF)/

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT_LIB)
		$(RM) $(FT_PRINTF_LIB)
		make fclean -C $(LIBFT)
		make fclean -C $(FT_PRINTF)

re: fclean all

.PHONY: all clean fclean re
