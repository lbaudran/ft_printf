/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:28:26 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/11 18:24:23 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int 			ft_printf(const char *fmt, ...)
{
	int			y;
	int			i;
	char		*line;
	va_list		ap;
	int a;

	line = (char *)malloc(ft_strlen(fmt));
	va_start(ap, fmt);
	i = 0;
	a = 0;
	while (fmt[i])
	{
		while (line[a])
			a++;
		if (fmt[i] == '%')
		{
			if ((line = stock_str(&ap, &i, line, fmt)) == NULL)
				return (-1);
		}
		else
			line[a++] = fmt[i++];
	}
	va_end(ap);
	ft_putstr(line);
	return (ft_strlen(line));
}

char			*stock_str(va_list *ap, int *i, char *line, const char *fmt)
{
	int				tab[8];
	t_list			*elem;

	elem = (t_list*)malloc(sizeof(t_list));
	reset_tab(tab, 8);
	if (check_start(i, fmt, ap, tab) == -1)
		return (NULL);
	if ((is_intforprintf(tab[7]) || tab[7] == 'p') && tab[7] != 'c')
	{
		elem->tmpint = va_arg(*ap, long double);
		putline_nbr(line, elem, tab);
	}
	else if (tab[7] == 's')
	{
		elem->tmpstr = va_arg(*ap, char *);
		putline_str(line, elem, tab);
	}
	free(elem);
	return(line);
}

char			*putline_str(char *line, t_list *elem, int *tab)
{
	
}
