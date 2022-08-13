/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:59:26 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/14 02:18:11 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_info *info)
{
	if (info->a.top->index > info->a.top->next->index)
		sa(info);
}

static void	sort_three(t_info *info)
{
	int	max;

	max = get_max_stack_index(&info->a);
	if (info->a.top->index == max)
		ra(info);
	else if (info->a.top->next->index == max)
		rra(info);
	if (info->a.top->index == max - 1)
		sa(info);
}

static void	push_index(t_info *info, int idx)
{
	int		pos;
	t_node	*node;

	pos = 0;
	node = info->a.top;
	while (node && node->index != idx)
	{
		pos++;
		node = node->next;
	}
	if (pos < info->a.size / 2)
	{
		while (info->a.top != node)
			ra(info);
	}
	else
	{
		while (info->a.top != node)
			rra(info);
	}
	pb(info);
}

void	sort(t_info *info)
{
	int	size;
	int	i;

	size = info->a.size;
	if (size < 2 || sorted_stack(&info->a))
		return ;
	if (size == 2)
		sort_two(info);
	else if (size == 3)
		sort_three(info);
	else if (size >= 4 && size <= 7)
	{
		i = 0;
		while (i <= size - 4)
			push_index(info, i++);
		sort_three(info);
		while (info->b.top)
			pa(info);
	}
	else
	{
		sort_a_to_b(info);
		sort_b_to_a(info);
	}
}
