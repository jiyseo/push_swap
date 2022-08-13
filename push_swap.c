/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:57:30 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 21:14:02 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;

	init_stack(&info.a);
	init_stack(&info.b);
	import_data(&info.a, argc, argv);
	info.cmd_print = 1;
	sort(&info);
	free_stack(&info.a);
	free_stack(&info.b);
	return (0);
}
