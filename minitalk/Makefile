# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yousong <yousong@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 17:49:06 by yousong           #+#    #+#              #
#    Updated: 2024/09/06 17:55:30 by yousong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.o libft
		$(CC) -o $@ $< -Llibft -lft

client: client.o libft
		$(CC) -o $@ $< -Llibft -lft

%.o: $.c
		$(CC) -c $(CFLAGS) $?

libft:
		make -C libft

clean:
		rm -f $(OBJECTS)
		make -C libft clean

fclean: clean
		rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re