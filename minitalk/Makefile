# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yousong <yousong@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 17:49:06 by yousong           #+#    #+#              #
#    Updated: 2024/09/07 14:10:21 by yousong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = server
NAMEC = client

SRCS = server.c
SRCC = client.c

OBJS = $(SRCS:.c=.o)
OBJC = $(SRCC:.c=.o)

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAMES) $(NAMEC)

$(LIBFT):
		make -C libft

$(NAMES): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAMES) $(OBJS) $(LIBFT)

$(NAMEC): $(OBJC) $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAMEC) $(OBJC) $(LIBFT)

$(OBJS): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJC): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS) $(OBJC)
		make -C libft clean

fclean: clean
		rm -f $(NAMES) $(NAMEC) $(OBJC) $(OBJS)
		make -C libft fclean

re: fclean all

.PHONY: all libft clean fclean re