
BIN	= push_swap
CK_BIN	= checker

DIR_FT	= Libft
DIR_PR	= ft_printf
LIB_FT	= $(DIR_FT)/libft.a
LIB_PR	= $(DIR_PR)/libftprintf.a

COMM_SRCS = push_swap_utils.c \
	  command.c \
	  command_rotate.c \
	  command_same.c \
	  command_utils.c \
	  stack.c \
	  stack_index.c \
	  stack_utils.c

SRCS	= push_swap.c \
	  sort.c \
	  sort_utils.c \
	  $(COMM_SRCS)

OBJS	= $(SRCS:.c=.o)

CK_SRCS	= checker.c \
	  checker_utils.c \
	  $(COMM_SRCS)

CK_OBJS	= $(CK_SRCS:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
INCS	= -I./$(DIR_FT) -I./$(DIR_PR)/

$(BIN): $(LIB_FT) $(LIB_PR) $(OBJS)
	$(CC) -o $@ $(OBJS) -L./$(DIR_FT) -lft -L./$(DIR_PR) -lftprintf

$(LIB_FT):
	make -C $(DIR_FT)

$(LIB_PR):
	make -C $(DIR_PR)

$(CK_BIN): $(LIB_FT) $(LIB_PR) $(CK_OBJS)
	$(CC) -o $@ $(CK_OBJS) -L./$(DIR_FT) -lft -L./$(DIR_PR) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

.PHONY: all bonus clean fclean re

all: $(BIN) $(CK_BIN)

bonus:
	make WITH_BONUS=1 $(CK_BIN)

clean:
	rm -f *.o
	make clean -C $(DIR_FT)
	make clean -C $(DIR_PR)

fclean:
	rm -f *.o $(BIN) $(CK_BIN)
	make fclean -C $(DIR_FT)
	make fclean -C $(DIR_PR)

re: fclean all
