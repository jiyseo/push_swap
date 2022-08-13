/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:02:42 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/14 03:49:08 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	init_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	node = stack->top;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	init_stack(stack);
}

int	sorted_stack(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->top;
	while (node)
	{
		if (node->index != i)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}
