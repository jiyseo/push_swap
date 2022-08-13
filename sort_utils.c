/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:00:34 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/14 03:38:55 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_to_b(t_info *info)
{
	int		chunk;
	int		idx;

	chunk = 0.027 * info->a.size + 14.642;
	idx = 0;
	while (info->a.top)
	{
		if (info->a.top->index <= idx)
		{
			pb(info);
			idx++;
		}
		else if (info->a.top->index > idx && info->a.top->index <= idx + chunk)
		{
			pb(info);
			rb(info);
			idx++;
		}
		else if (info->a.top->index > idx + chunk)
			ra(info);
	}
}

static void	rotate_b(t_info *info, t_node *node, int pos)
{
	if (pos < info->b.size / 2)
	{
		while (info->b.top != node)
			rb(info);
	}
	else
	{
		while (info->b.top != node)
			rrb(info);
	}
}

void	sort_b_to_a(t_info *info)
{
	int		pos;
	t_node	*node;

	pos = 0;
	node = info->b.top;
	while (node)
	{
		if (node->index == info->b.size - 1)
		{
			rotate_b(info, node, pos);
			pa(info);
			pos = 0;
			node = info->b.top;
		}
		else
		{
			node = node->next;
			pos++;
		}
	}
}
