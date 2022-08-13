/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:56:24 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 18:57:21 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmd_swap(t_stack *stack)
{
	t_node	*top;
	t_node	*next;

	if (stack->top == stack->bottom)
		return (0);
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
	return (1);
}

int	cmd_push(t_stack *dest, t_stack *src)
{
	if (!src->top)
		return (0);
	push_top(dest, pop_top(src));
	return (1);
}

int	cmd_rotate(t_stack *stack)
{
	if (stack->top == stack->bottom)
		return (0);
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->bottom = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
	return (1);
}

int	cmd_rev_rotate(t_stack *stack)
{
	if (stack->top == stack->bottom)
		return (0);
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	stack->top = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
	return (1);
}
