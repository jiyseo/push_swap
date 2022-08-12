#include "push_swap.h"

void	error_exit(char *msg)
{
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
	exit(1);
}

static int	get_num(const char	*str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (!*str)
		error_exit("not an integer");
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - '0') * sign;
		if (n > INT_MAX || n < INT_MIN)
			error_exit("not an integer");
		str++;
	}
	if (*str)
		error_exit("not an integer");
	return (n);
}

void import_argv(t_stack *stack, int argc, char **argv)
{
	int		i;
	char	**arr;
	t_node	*node;

	if (argc < 2)
		error_exit("argc error");
	while (*++argv)
	{
		arr = ft_split(*argv, ' ');
		if (!arr)
			error_exit("out of memory error");
		if (!arr[0])
			error_exit("not an integer");
		i = 0;
		while (arr[i])
		{
			node = alloc_node(get_num(arr[i]));
			push_bottom(stack, node);
			i++;
		}
		ft_free_array(arr);
	}
}
