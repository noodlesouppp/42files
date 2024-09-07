# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yousong <yousong@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/06 17:49:06 by yousong           #+#    #+#              #
#    Updated: 2024/09/07 20:32:33 by yousong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = server
NAMEC = client

BONUS_NAMES = server_bonus
BONUS_NAMEC = client_bonus

SRCS = server.c
SRCC = client.c

BONUSSRCS = server_bonus.c
BONUSSRCC = client_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJC = $(SRCC:%.c=%.o)

BONUSOBJS = $(BONUSSRCS:%.c=%.o)
BONUSOBJC = $(BONUSSRCC:%.c=%.o)

LIBFT = libft/libft.a

CC = gcc

DEBUG_FLAGS = -g3 -gdwarf-3 -fsanitize=address -fsanitize=undefined

ifdef DEBUG
	CFLAGS = -Wall -Wextra -Werror $(DEBUG_FLAGS)
else
	CFLAGS = -Wall -Wextra -Werror
endif

all: $(NAMES) $(NAMEC)

$(LIBFT):
		@$(MAKE) -C libft

$(NAMES): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAMES) $(OBJS) $(LIBFT)

$(NAMEC): $(OBJC) $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAMEC) $(OBJC) $(LIBFT)



bonus: $(BONUS_NAMES) $(BONUS_NAMEC)

$(BONUS_NAMES): $(BONUSOBJS) $(LIBFT)
		$(CC) $(CFLAGS) -o $(BONUS_NAMES) $(BONUSOBJS) $(LIBFT)

$(BONUS_NAMEC): $(BONUSOBJC) $(LIBFT)
		$(CC) $(CFLAGS) -o $(BONUS_NAMEC) $(BONUSOBJC) $(LIBFT)



$(OBJS): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJC): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(BONUSOBJS): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(BONUSOBJC): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -f $(OBJS) $(OBJC) $(BONUSOBJS) $(BONUSOBJC)
		@$(MAKE) -C libft clean

fclean: clean
		rm -f $(NAMES) $(NAMEC) $(OBJC) $(OBJS) $(BONUS_NAMES) $(BONUS_NAMEC) $(BONUSOBJC) $(BONUSOBJS)
		@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all libft clean fclean re
