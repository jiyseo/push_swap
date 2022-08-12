
BIN	= push_swap
DIR_FT	= Libft
DIR_PR	= ft_printf
LIB_FT	= $(DIR_FT)/libft.a
LIB_PR	= $(DIR_PR)/libftprintf.a
SRCS	= push_swap.c \
	  push_swap_utils.c \
	  command.c \
	  command_rotate.c \
	  command_same.c \
	  command_utils.c \
	  stack.c \
	  stack_utils.c
OBJS	= $(SRCS:.c=.o)
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
INCS	= -I./$(DIR_FT) -I./$(DIR_PR)/

.PHONY: all bonus clean fclean re

all: $(BIN)

$(LIB_FT):
	make -C $(DIR_FT)

$(LIB_PR):
	make -C $(DIR_PR)

$(BIN): $(LIB_FT) $(LIB_PR) $(OBJS)
	$(CC) -o $@ $(OBJS) -L./$(DIR_FT) -lft -L./$(DIR_PR) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

bonus:
	make WITH_BONUS=1 all

clean:
	rm -f *.o
	make clean -C $(DIR_FT)
	make clean -C $(DIR_PR)

fclean:
	rm -f *.o $(BIN)
	make fclean -C $(DIR_FT)
	make fclean -C $(DIR_PR)

re: fclean all
