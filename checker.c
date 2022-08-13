/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:52:42 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 18:53:19 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_finish(t_info *info, int ok)
{
	if (ok && (!sorted_stack(&info->a) || info->b.size > 0))
		ok = 0;
	free_stack(&info->a);
	free_stack(&info->b);
	if (ok)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static void	check_init(t_info *info, int argc, char **argv)
{
	init_stack(&info->a);
	init_stack(&info->b);
	import_data(&info->a, argc, argv);
	info->cmd_print = 0;
}

int	main(int argc, char **argv)
{
	t_info	info;
	char	*line;
	int		ok;

	check_init(&info, argc, argv);
	ok = 1;
	while (read_line(&line))
	{
		if (!chk_cmd(&info, line) && !chk_cmd_rotate(&info, line))
		{
			free(line);
			ok = 0;
			break ;
		}
		free(line);
	}
	check_finish(&info, ok);
	return (0);
}
