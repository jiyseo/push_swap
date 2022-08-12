#include "push_swap.h"

void	*mem_alloc(int size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
		error_exit("out of memory error");
	return (mem);
}

t_node	*alloc_node(int data)
{
	t_node	*node;

	node = (t_node *)mem_alloc(sizeof(t_node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	init_stack(t_stack *stack)
{
	stack->count = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

void	free_stack(t_stack *stack)
{
	t_node *node;
	t_node *next;

	node = stack->top;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	init_stack(stack);
}
