NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = push_swap.c list_utils.c push.c swap.c rotate.c reverse_rotate.c split.c utils.c check_input_utils.c check_input.c sort_small.c sort_range.c

SRC_BNS = checker_bonus.c checker_utils_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c list_utils.c push.c swap.c rotate.c reverse_rotate.c split.c utils.c check_input_utils.c check_input.c sort_small.c sort_range.c

OBJ = $(SRC:.c=.o)

OBJ_BNS = $(SRC_BNS:.c=.o)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME) bonus

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BNS)
	$(CC) $(CFLAGS) $(OBJ_BNS) -o $(BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: clean