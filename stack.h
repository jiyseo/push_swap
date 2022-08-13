/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:16:16 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 19:16:18 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bottom;
	int			size;
}	t_stack;

void	*mem_alloc(int size);
t_node	*alloc_node(int data);
void	init_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int		sorted_stack(t_stack *stack);

void	update_stack_index(t_stack *stack, t_node *new_node);
int		get_max_stack_index(t_stack *stack);

void	push_top(t_stack *stack, t_node *node);
void	push_bottom(t_stack *stack, t_node *node);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);
void	print_stack(t_stack *stack);

#endif
