NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC_DIR = srcs
COMMANDS_DIR = $(SRC_DIR)/commands
PUSH_SWAP_DIR = $(SRC_DIR)/push_swap

SRCS = $(COMMANDS_DIR)/big_sort.c \
		$(COMMANDS_DIR)/push.c \
		$(COMMANDS_DIR)/reverse_rotate.c \
		$(COMMANDS_DIR)/rotate.c \
		$(COMMANDS_DIR)/small_sort.c \
		$(COMMANDS_DIR)/swap.c \
		$(PUSH_SWAP_DIR)/error_utils.c \
		$(PUSH_SWAP_DIR)/finalise_sort.c \
		$(PUSH_SWAP_DIR)/initiate_sort.c \
		$(PUSH_SWAP_DIR)/initiate_stack.c \
		$(PUSH_SWAP_DIR)/main.c \
		$(PUSH_SWAP_DIR)/ps_split.c \
		$(PUSH_SWAP_DIR)/sort_utils.c \
		$(PUSH_SWAP_DIR)/stack_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
