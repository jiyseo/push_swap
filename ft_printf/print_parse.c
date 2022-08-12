/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:22:36 by jiyseo            #+#    #+#             */
/*   Updated: 2022/05/19 17:11:50 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_util.h"

static int	get_width(t_pfinfo *inf)
{
	int	width;

	width = 0;
	if (*inf->fmt == '*')
	{
		inf->fmt++;
		width = va_arg(inf->ap, int);
	}
	else
	{
		while ((*inf->fmt >= '0') && (*inf->fmt <= '9'))
		{
			width = width * 10 + (*inf->fmt - '0');
			inf->fmt++;
		}
	}
	return (width);
}

static void	parse_flags(t_pfinfo *inf)
{
	inf->flag = 0;
	while (*++inf->fmt)
	{
		if (*inf->fmt == '-')
			inf->flag |= FLAG_MINUS;
		else if (*inf->fmt == '+')
			inf->flag |= FLAG_PLUS;
		else if (*inf->fmt == ' ')
			inf->flag |= FLAG_SPACE;
		else if (*inf->fmt == '0')
			inf->flag |= FLAG_ZERO;
		else if (*inf->fmt == '#')
			inf->flag |= FLAG_SHARP;
		else
			break ;
	}
}

static void	parse_width(t_pfinfo *inf)
{
	inf->width = get_width(inf);
	if (inf->width < 0)
	{
		inf->width = -inf->width;
		inf->flag |= FLAG_MINUS;
	}
	if (*inf->fmt == '.')
	{
		inf->fmt++;
		inf->precision = get_width(inf);
		inf->flag &= ~FLAG_ZERO;
	}
	else
		inf->precision = -1;
}

void	parse_format(t_pfinfo *inf)
{
	parse_flags(inf);
	parse_width(inf);
	inf->type = *inf->fmt++;
	if (inf->type == '%')
		put_char(inf, '%');
	else if (inf->type == 'c')
		print_char(inf, va_arg(inf->ap, int));
	else if (inf->type == 's')
		print_string(inf, va_arg(inf->ap, char *));
	else if (inf->type == 'd' || inf->type == 'i')
		print_nbr(inf, va_arg(inf->ap, int), 10);
	else if (inf->type == 'u')
		print_nbr(inf, va_arg(inf->ap, unsigned int), 10);
	else if (inf->type == 'x' || inf->type == 'X')
		print_nbr(inf, va_arg(inf->ap, unsigned int), 16);
	else if (inf->type == 'p')
		print_nbr(inf, (unsigned long long)va_arg(inf->ap, void *), 16);
	else
		put_char(inf, inf->type);
}
