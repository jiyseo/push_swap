#include "push_swap.h"

void	ra(t_info *info)
{
	ft_printf("ra\n");
	cmd_rotate(&info->a);
}

void	rb(t_info *info)
{
	ft_printf("rb\n");
	cmd_rotate(&info->b);
}

void	rra(t_info *info)
{
	ft_printf("rra\n");
	cmd_rev_rotate(&info->a);
}

void	rrb(t_info *info)
{
	ft_printf("rrb\n");
	cmd_rev_rotate(&info->b);
}
