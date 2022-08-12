#include "push_swap.h"

void	dump_node(t_node *node, int size)
{
	if (node)
		printf(" %*d", size, node->data);
	else
		printf(" %*c", size, ' ');
}

void	dump_stack(t_info *info)
{
	t_node	*a_node;
	t_node	*b_node;

	a_node = info->a.top;
	b_node = info->b.top;
	while (a_node || b_node)
	{
		dump_node(a_node, 3);
		dump_node(b_node, 3);
		printf("\n");
		if (a_node)
			a_node = a_node->next;
		if (b_node)
			b_node = b_node->next;
	}
	printf(" --- ---\n  a   b\n");
}

int main(int argc, char **argv)
{
	t_info	info;

	init_stack(&info.a);
	init_stack(&info.b);
	import_argv(&info.a, argc, argv);
	printf("stack a : "); print_stack(&info.a);

sa(&info);dump_stack(&info);
pb(&info);
pb(&info);
pb(&info);dump_stack(&info);
rr(&info);dump_stack(&info);
rrr(&info);dump_stack(&info);
sa(&info);dump_stack(&info);
pa(&info);
pa(&info);
pa(&info);dump_stack(&info);
	printf("stack a : "); print_stack(&info.a);
	printf("stack b : "); print_stack(&info.b);
/*
	printf("1. test sa()\n");
	sa(&info);
	printf("stack a : "); print_stack(&info.a);

	printf("2. test ra()\n");
	ra(&info);
	printf("stack a : "); print_stack(&info.a);

	printf("3. test rra()\n");
	rra(&info);
	printf("stack a : "); print_stack(&info.a);

	printf("4. test pb()\n");
	pb(&info);
	printf("stack a : "); print_stack(&info.a);
	printf("stack b : "); print_stack(&info.b);

	printf("5. test pb()\n");
	pb(&info);
	printf("stack a : "); print_stack(&info.a);
	printf("stack b : "); print_stack(&info.b);

	printf("6. test pa()\n");
	pa(&info);
	printf("stack a : "); print_stack(&info.a);
	printf("stack b : "); print_stack(&info.b);

	printf("7. test pa()\n");
	pa(&info);
	printf("stack a : "); print_stack(&info.a);
	printf("stack b : "); print_stack(&info.b);
*/


	free_stack(&info.a);
	free_stack(&info.b);


/*	t_stack s;
	init_stack(&s);
	printf("1. test push_top()\n");
	push_top(&s, alloc_node(10));
	print_stack(&s);
	push_top(&s, alloc_node(20));
	print_stack(&s);
	free_stack(&s);

	printf("\n2. test push_bottom()\n");
	push_bottom(&s, alloc_node(30));
	print_stack(&s);
	push_bottom(&s, alloc_node(40));
	print_stack(&s);

	printf("\n3. test pop_top()\n");
	free(pop_top(&s));
	print_stack(&s);
	free(pop_top(&s));
	print_stack(&s);

	printf("\n3. test pop_bottom()\n");
	push_bottom(&s, alloc_node(30));
	push_bottom(&s, alloc_node(40));
	print_stack(&s);
	free(pop_bottom(&s));
	print_stack(&s);
	free(pop_bottom(&s));
	print_stack(&s);
*/
	return (1);
}
