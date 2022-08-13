/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:01:16 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 21:13:49 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->prev = NULL;
	node->next = stack->top;
	stack->top = node;
	if (!stack->bottom)
		stack->bottom = node;
	if (node->next)
		node->next->prev = node;
	stack->size++;
}

void	push_bottom(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	update_stack_index(stack, node);
	node->prev = stack->bottom;
	node->next = NULL;
	stack->bottom = node;
	if (!stack->top)
		stack->top = node;
	if (node->prev)
		node->prev->next = node;
	stack->size++;
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
		stack->size--;
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
		stack->size--;
	}
	return (node);
}
