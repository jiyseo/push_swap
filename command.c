/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:51:49 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 18:55:27 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	if (cmd_swap(&info->a) && info->cmd_print)
		ft_printf("sa\n");
}

void	sb(t_info *info)
{
	if (cmd_swap(&info->b) && info->cmd_print)
		ft_printf("sb\n");
}

void	pa(t_info *info)
{
	if (cmd_push(&info->a, &info->b) && info->cmd_print)
		ft_printf("pa\n");
}

void	pb(t_info *info)
{
	if (cmd_push(&info->b, &info->a) && info->cmd_print)
		ft_printf("pb\n");
}
