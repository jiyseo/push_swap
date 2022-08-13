/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:18:25 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 19:18:46 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "stack.h"

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_info
{
	t_stack	a;
	t_stack	b;
	int		cmd_print;
}	t_info;

void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

int		cmd_swap(t_stack *stack);
int		cmd_push(t_stack *dest, t_stack *src);
int		cmd_rotate(t_stack *stack);
int		cmd_rev_rotate(t_stack *stack);

void	sort(t_info *info);
void	sort_a_to_b(t_info *info);
void	sort_b_to_a(t_info *info);

void	error_exit(char *msg);
void	import_data(t_stack *stack, int argc, char **argv);

#endif
