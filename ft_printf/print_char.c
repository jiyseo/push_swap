/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:15:59 by jiyseo            #+#    #+#             */
/*   Updated: 2022/05/18 20:09:05 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_util.h"

void	print_char(t_pfinfo *inf, char ch)
{
	inf->width--;
	fill_left(inf);
	put_char(inf, ch);
	fill_right(inf);
}
