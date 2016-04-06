/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:28:26 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/30 17:26:42 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int 			ft_printf(const char *fmt, ...)
{
	int			y;
	int			i;
	char		*line;
	va_list		ap;

	line = (char *)malloc(ft_strlen(fmt));
	va_start(ap, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			y = 1;
			while (fmt[i - y] == '\\')
				y++;
			if (y % 2 == 1)
				if (!(stock_str(&ap, &i, line, fmt)))
					return (-1);
		}
	}
	va_end(ap);
	ft_putstr(line);
	return (ft_strlen(line));
}

char			*stock_str(va_list *ap, int *i, char *line, const char *fmt)
{
	int				tab[8];
	int				n;
	char			*tmp;
	long double		tmpint;
	char			test;

	n = 0;
	while (tab[n++] <= 8)
		tab[n] = 0;
	n = 0;
	if (check_start(i, fmt, ap, tab) == -1)
		return (0);
	if ((is_intforprintf(tab[7]) || tab[7] == 'p') && tab[7] != 'c')
		tmpint = va_arg(*ap, long double);
	if (tab[7] == 'c')
		test = va_arg(*ap, int);
	if (tab[7] == 's')
		tmp = va_arg(*ap, char *);
	return(line);
}

/*
void			start_write(const char* format, t_list *begin)
{
	int		i;
	int		n;
	int		y;

	n = 0;
	i = 0;
	y = 1;
	while (format[i])
	{
		if (format[i] == '%')
		{
			while (format[i - y] == '\\')
				y++;
			if (y % 2 == 1)
				check_start(i, format, begin);
			else
			{
				ft_putchar(format[i++]);
				begin->nbr++;
			}
		}
		else
		{
			ft_putchar(format[i++]);
			begin->nbr++;
		}
	}
}



while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			y = 1;
			while (fmt[i - y++] == '\\');
			if (y % 2 == 1)
			{
				while (NOARG(fmt[++i]));
				if (ft_isdigit(fmt[i]))
					stock_tab(begin, i, fmt);
				if (fmt[i] == '*' && (NOARG(fmt[i - 1] || fmt[i - 1] == '%')))
				{
					stock_star(begin, va_arg(ap, int), 0);
					i++;
					if (fmt[i] == '.' && fmt[i++] == '*')
						stock_star(begin, va_arg(ap, int), 1);
				}
				if (is_intforprintf(fmt[i]))
					create_list(begin, fmt[i],ft_itoa(va_arg(ap, int)));
				else if (fmt[i] == 's')
					create_list(begin, fmt[i],va_arg(ap, char *));
				else
					return (-1);
			}
		}
		i++;
	}
*/
