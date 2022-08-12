#include "push_swap.h"

void	cmd_swap(t_stack *stack)
{
	t_node	*top;
	t_node	*next;

	if (stack->top == stack->bottom)
		return;
	top = stack->top;
	next = top->next;
	top->prev = next;
	top->next = next->next;
	if (next->next)
		next->next->prev = top;
	next->prev = NULL;
	next->next = top;
	stack->top = next;
	if (stack->bottom == next)
		stack->bottom = top;
}

void	cmd_push(t_stack *dest, t_stack *src)
{
	if (src->top)
		push_top(dest, pop_top(src));
}

void	cmd_rotate(t_stack *stack)
{
	if (stack->top == stack->bottom)
		return;
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->bottom = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
}

void	cmd_rev_rotate(t_stack *stack)
{
	if (stack->top == stack->bottom)
		return;
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->top = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
}
