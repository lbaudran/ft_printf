/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:28:26 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/22 17:48:40 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"


int				ft_printf(const char * format, ...)
{
	int i;
	int n;
	int y;
	va_list ap;

	n = 0;
	i = 0;
	y = 0;
	va_start(ap, format);
	while (format[i])
	{
/*		if (format[i] == '%')
		{
			while (format[i - y] == '\\')
				y++;
			if (y % 2 == 0)
				n = check_start(i, format, ap);
			else
				ft_putchar(format[i++]);
		}
		else
*/			ft_putchar(format[i++]);
	}
		return(i - n);
}
