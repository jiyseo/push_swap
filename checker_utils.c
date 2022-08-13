/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:53:29 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 18:54:18 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

int	read_line(char **line)
{
	char	*ptr;

	ptr = get_next_line(STDIN_FILENO);
	if (!ptr)
		return (0);
	*line = ptr;
	if (*ptr)
	{
		ptr += ft_strlen(ptr) - 1;
		if (*ptr == '\n')
			*ptr = '\0';
	}
	return (1);
}

int	chk_cmd(t_info *info, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(info);
	else if (ft_strcmp(line, "sb") == 0)
		sb(info);
	else if (ft_strcmp(line, "ss") == 0)
		ss(info);
	else if (ft_strcmp(line, "pa") == 0)
		pa(info);
	else if (ft_strcmp(line, "pb") == 0)
		pb(info);
	else
		return (0);
	return (1);
}

int	chk_cmd_rotate(t_info *info, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		ra(info);
	else if (ft_strcmp(line, "rb") == 0)
		rb(info);
	else if (ft_strcmp(line, "rr") == 0)
		rr(info);
	else if (ft_strcmp(line, "rra") == 0)
		rra(info);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(info);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(info);
	else
		return (0);
	return (1);
}
