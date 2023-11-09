NAME :=        libft.a
SRCS :=        ft_strlen.c
OBJS :=        $(SRCS:.c=.o)

CC :=        cc
CFLAGS :=    -Wall -Wextra -Werror

AR :=        ar rcs

RM :=        rm -f

%.o:        %.c
	            $(CC) $(CFLAGS) -I ./includes -c $< -o $@

so: $(OBJS)
		$(CC) -fPIC $(CFLAGS) -I./includes -c $(SRCS)
			gcc -shared -o libft.so $(OBJS)

$(NAME):    $(OBJS)
	            $(AR) $@ $^

all:        $(NAME)

clean:
	            $(RM) $(OBJS)

fclean:        clean
	            $(RM) $(NAME)

re:            fclean all

.PHONY:        all clean fclean re

