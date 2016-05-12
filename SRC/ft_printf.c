/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:28:26 by lbaudran          #+#    #+#             */
/*   Updated: 2016/05/02 15:17:33 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <locale.h>

void		ft_clear_struct(t_list *elem)
{
	free(elem->line);
	free(elem->unicode);
	free(elem);
}

t_list		*create_struct(const char *fmt)
{
	t_list		*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	elem->index = 0;
	elem->aff_null = 0;
	elem->aff_null_w = 0;
	elem->line = (char *)malloc((ft_strlen(fmt) + 1) * sizeof(char));
	elem->unicode = (wchar_t *)malloc((ft_strlen(fmt) + 1) * sizeof(wchar_t *));
	ft_bzero(elem->line, ft_strlen(fmt) + 1);
	ft_bzero(elem->unicode, ft_strlen(fmt) + 1);
	return (elem);
}

void		ft_putprintf(int *tab, t_list *elem)
{
	int		i;

	i = 0;
	while (elem->line[i] || elem->aff_null != 0)
	{
		if (elem->aff_null && elem->line[i] == '\0')
			elem->index += write(1, &elem->line[i++], (elem->aff_null)--);
		else if (elem->line[i])
			elem->index += write(1, &elem->line[i++], 1);
	}
	ft_bzero(elem->line, i);
	i = 0;
	while (elem->unicode[i] || elem->aff_null_w != 0)
	{
		if (elem->unicode[i] == '\0' && elem->aff_null_w)
		{
			elem->aff_null_w = 0;
			elem->index += write(1, "\0", 1);
		}
		else
			ft_printwchar(elem->unicode[i], elem);
		i++;
	}
	elem->unicode[0] = '\0';
	ft_bzero(elem->unicode, i);
}

int			ft_printf(const char *fmt, ...)
{
	int			a;
	int			i;
	t_list		*elem;
	va_list		ap;

	elem = create_struct(fmt);
	va_start(ap, fmt);
	i = 0;
	a = 0;
	while (fmt[i])
	{
		a = ft_strlen(elem->line);
		if (fmt[i] == '%')
			elem->line = stock_str(&ap, &i, elem, fmt);
		else
			elem->line[a++] = fmt[i++];
	}
	va_end(ap);
	elem->index += write(1, elem->line, ft_strlen(elem->line));
	i = elem->index;
	ft_clear_struct(elem);
	return (elem->index);
}

char		*stock_str(va_list *ap, int *i, t_list *elem, const char *fmt)
{
	int				*tab;

	tab = (int *)malloc(9 * sizeof(int));
	reset_tab(tab, 9);
	if (fmt[(*i)] != '%')
		return (elem->line);
	if (check_start(i, fmt, ap, tab) == -1)
		return (NULL);
	elem->line = print_arg(tab, ap, elem, fmt);
	free(tab);
	return (elem->line);
}
