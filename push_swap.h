#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "stack.h"

#define INT_MAX	2147483647
#define INT_MIN	-2147483648

typedef struct s_info
{
	t_stack	a;
	t_stack	b;
}	t_info;

void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

void	cmd_swap(t_stack *stack);
void	cmd_push(t_stack *dest, t_stack *src);
void	cmd_rotate(t_stack *stack);
void	cmd_rev_rotate(t_stack *stack);

void	error_exit(char *msg);
void	import_argv(t_stack *stack, int argc, char **argv);

#endif
