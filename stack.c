#include "push_swap.h"

void	push_top(t_stack *stack, t_node *node)
{
	if(!node)
		return ;
	node->prev = NULL;
	node->next = stack->top;
	stack->top = node;
	if (!stack->bottom)
		stack->bottom = node;
	if (node->next)
		node->next->prev = node;
	stack->count++;
}

void	push_bottom(t_stack *stack, t_node *node)
{
	if(!node)
		return ;
	node->prev = stack->bottom;
	node->next = NULL;
	stack->bottom = node;
	if (!stack->top)
		stack->top = node;
	if (node->prev)
		node->prev->next = node;
	stack->count++;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (node)
	{
		stack->top = node->next;
		if (stack->top)
			stack->top->prev = NULL;
		if (stack->bottom == node)
			stack->bottom = node->next;
		stack->count--;
	}
	return (node);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*node;

	node = stack->bottom;
	if (node)
	{
		stack->bottom = node->prev;
		if (stack->bottom)
			stack->bottom->next = NULL;
		if (stack->top == node)
			stack->top = node->prev;
		stack->count--;
	}
	return (node);
}

#define HEX2(addr)	((int)((unsigned long long)(addr) & 0xFFFF))

void	print_stack(t_stack *stack)
{
	t_node	*node;

	printf("top:%04X bottom:%04X count: %d\n", HEX2(stack->top), HEX2(stack->bottom), stack->count);
	node = stack->top;
	while (node)
	{
		printf("	%04X [P:%04X N:%04X data: %d]\n", HEX2(node), HEX2(node->prev), HEX2(node->next), node->data);
		node = node->next;
	 }
}
