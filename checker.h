/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:16:47 by jiyseo            #+#    #+#             */
/*   Updated: 2022/08/13 19:17:51 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int	read_line(char **line);
int	chk_cmd(t_info *info, char *line);
int	chk_cmd_rotate(t_info *info, char *line);

#endif
