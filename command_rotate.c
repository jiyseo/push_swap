/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:55:45 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 18:55:46 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	if (cmd_rotate(&info->a) && info->cmd_print)
		ft_printf("ra\n");
}

void	rb(t_info *info)
{
	if (cmd_rotate(&info->b) && info->cmd_print)
		ft_printf("rb\n");
}

void	rra(t_info *info)
{
	if (cmd_rev_rotate(&info->a) && info->cmd_print)
		ft_printf("rra\n");
}

void	rrb(t_info *info)
{
	if (cmd_rev_rotate(&info->b) && info->cmd_print)
		ft_printf("rrb\n");
}
