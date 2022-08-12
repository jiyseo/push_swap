#include "push_swap.h"

void	ss(t_info *info)
{
	ft_printf("ss\n");
	cmd_swap(&info->a);
	cmd_swap(&info->b);
}

void	rr(t_info *info)
{
	ft_printf("rr\n");
	cmd_rotate(&info->a);
	cmd_rotate(&info->b);
}

void	rrr(t_info *info)
{
	ft_printf("rrr\n");
	cmd_rev_rotate(&info->a);
	cmd_rev_rotate(&info->b);
}
