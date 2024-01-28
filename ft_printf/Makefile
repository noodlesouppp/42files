# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yousong <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 20:25:05 by yousong           #+#    #+#              #
#    Updated: 2024/01/28 20:30:34 by yousong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror

RM := rm -f
AR := ar rcs

HEADER := ft_printf.h

NAME := libftprintf.a
SRCS_LIBFT := $(addprefix libft/, ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c \
			ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \
			ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c ft_putstr_fd.c \
			ft_bzero.c ft_putnbr_fd.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c)
SRCS := ft_printf_utils.c ft_print_hex_utils.c ft_print_ptr_utils.c ft_print_unsigned_utils.c ft_printf.c

OBJS := $(SRCS:.c=.o)
OBJS_LIBFT := $(SRCS_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_LIBFT)
		@$(AR) $(NAME) $(OBJS) $(OBJS_LIBFT)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		$(RM) $(OBJS) $(OBJS_LIBFT)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
	
