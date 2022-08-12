#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int			count;
	t_node		*top;
	t_node		*bottom;
}	t_stack;

void	*mem_alloc(int size);
void	init_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	push_top(t_stack *stack, t_node *node);
void	push_bottom(t_stack *stack, t_node *node);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);
t_node	*alloc_node(int data);
void	print_stack(t_stack *stack);

#endif
