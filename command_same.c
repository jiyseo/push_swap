/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_same.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:56:05 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 18:56:06 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_info *info)
{
	int	sa;
	int	sb;

	sa = cmd_swap(&info->a);
	sb = cmd_swap(&info->b);
	if (info->cmd_print)
	{
		if (sa && sb)
			ft_printf("ss\n");
		else if (sa)
			ft_printf("sa\n");
		else if (sb)
			ft_printf("sb\n");
	}
}

void	rr(t_info *info)
{
	int	ra;
	int	rb;

	ra = cmd_rotate(&info->a);
	rb = cmd_rotate(&info->b);
	if (info->cmd_print)
	{
		if (ra && rb)
			ft_printf("rr\n");
		else if (ra)
			ft_printf("ra\n");
		else if (rb)
			ft_printf("rb\n");
	}
}

void	rrr(t_info *info)
{
	int	rra;
	int	rrb;

	rra = cmd_rev_rotate(&info->a);
	rrb = cmd_rev_rotate(&info->b);
	if (info->cmd_print)
	{
		if (rra && rrb)
			ft_printf("rrr\n");
		else if (rra)
			ft_printf("rra\n");
		else if (rrb)
			ft_printf("rrb\n");
	}
}
