# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yousong <yousong@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 03:24:09 by yousong           #+#    #+#              #
#    Updated: 2024/09/04 16:39:29 by yousong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

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

HEADER = so_long.h

LIBFT = libft
LIBFT_LIB = libft.a
LIBFT_PATH = $(LIBFT)/$(LIBFT_LIB)

FT_PRINTF = ft_printf
FT_PRINTF_LIB = libftprintf.a
FT_PRINTF_PATH = $(FT_PRINTF)/$(FT_PRINTF_LIB)

AR = ar rc

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH) $(FT_PRINTF_PATH)
		$(CC) -o $(NAME) $(OBJS) -Llibft -lft -L$(FT_PRINTF) -lftprintf -Lmlx_linux -lmlx_Linux -L./mlx_linux -Imlx_linux -lXext -lX11 -lm -lz

%.o: %.c $(HEADER)
		$(CC) $(FLAGS) -c $< -I./ -I$(LIBFT) -I$(FT_PRINTF) -o $@

$(LIBFT_PATH):
		make -C $(LIBFT)

$(FT_PRINTF_PATH):
		make -C $(FT_PRINTF)

clean:
		$(RM) $(OBJS)
		make -C $(LIBFT) clean
		make -C $(FT_PRINTF) clean

fclean: clean
		$(RM) $(NAME)
		make -C $(LIBFT) fclean
		make -C $(FT_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
