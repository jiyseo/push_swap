/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:16:29 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/25 00:50:26 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_UTIL_H
# define PRINT_UTIL_H

# include <stdio.h>
# include <unistd.h>
# include "ft_printf.h"

int		put_char(t_pfinfo *inf, char c);
void	fill_char(t_pfinfo *inf, char ch, int count);
void	fill_left(t_pfinfo *inf);
void	fill_right(t_pfinfo *inf);
void	print_char(t_pfinfo *inf, char ch);
void	print_string(t_pfinfo *inf, char *str);
void	print_nbr(t_pfinfo *inf, unsigned long long nbr, int radix);
int		print_format(t_pfinfo *inf, const char *format);
void	parse_format(t_pfinfo *inf);

#endif
