NAME = push_swap 

SRC = push_swap.c push_swap_movements_1.c push_swap_movements_2.c push_swap_movements_3.c ft_sort_upTo3.c ft_sort_upTo5_1.c ft_sort_upTo5_2.c ft_sort_upTo100_1.c ft_sort_upTo100_2.c ft_sort_upTo100_3.c ft_sort_upTo100_4.c ft_error_handling.c ft_push_swap_utils.c ft_change_to_index.c ft_clear_argvs.c

OBJS = $(SRC: .c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -c $(OBJS) $(SRC)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME) 
	$(RM) push_swap.dSYM

re: fclean all

.PHONY: all clean fclean re
