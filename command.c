#include "push_swap.h"

void	sa(t_info *info)
{
	ft_printf("sa\n");
	cmd_swap(&info->a);
}

void	sb(t_info *info)
{
	ft_printf("sb\n");
	cmd_swap(&info->b);
}

void	pa(t_info *info)
{
	ft_printf("pa\n");
	cmd_push(&info->a, &info->b);
}

void	pb(t_info *info)
{
	ft_printf("pb\n");
	cmd_push(&info->b, &info->a);
}

