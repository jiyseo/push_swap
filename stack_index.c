/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:02:22 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/14 16:00:10 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stack_index(t_stack *stack, t_node *new_node)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (node->data == new_node->data)
			error_exit("Error");
		else if (node->data > new_node->data)
			node->index++;
		else if (node->data < new_node->data)
			new_node->index++;
		node = node->next;
	}
}

int	get_max_stack_index(t_stack *stack)
{
	int		max;
	t_node	*node;

	max = 0;
	node = stack->top;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (max);
}
