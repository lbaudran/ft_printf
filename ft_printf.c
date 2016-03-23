/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:28:26 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/23 18:39:04 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

t_list			*create_begin(void)
{
	t_list	*begin;
	int		i;

	i = 0 ;
	begin = (t_list*)malloc(sizeof(t_list));
	begin->next = NULL;
	begin->str = NULL;
	begin->nbr = 0;
	begin->tab = (int *)malloc(5);
	while (i <= 5)
		begin->tab[i++] = 0;
	return (begin);
}

void			create_list(t_list *begin,char c, char *s)
{
	t_list	*elem;

	elem = begin;
	while (elem->next)
		elem = elem->next;
	if (is_intforprintf(c))
	{
		elem->next = (t_list*)malloc(sizeof(t_list));
		elem->next->nbr = ft_atoi(s);
		elem->next->str = NULL;
		elem->next->next = NULL;
		elem->tab = NULL;
	}
	else
	{
		elem->next = (t_list*)malloc(sizeof(t_list));
		elem->next->nbr = 0;
		elem->next->str = (char *)malloc(ft_strlen(s));
		ft_strcpy(elem->next->str, s);
		elem->next->next = NULL;
		elem->tab = NULL;
	}
}
int			stock_star(t_list *begin, int c, int compt);
int			stock_tab(t_list *begin, int i, const char *format)
{
	char	tmp[12];
	int		n;

	n = 0;
	if (format[i - 1] == '.')
		n = 1;
	while (ft_isdigit(format[i]))
	{
		tmp[i] = format[i];
		i++;
	}
	if (n == 0)
		begin->tab[1] = ft_atoi(tmp);
	else
		begin->tab[2] = ft_atoi(tmp);
	if (format[i] == '.' && n == 0)
		i++;
	if (ft_isdigit(format[i]))
		stock_tab(begin, i, format);
	return (i);
	
}
int 			ft_printf(const char *fmt, ...)
{
	int			y;
	int			i;
	t_list		*begin;
	va_list		ap;

	begin = create_begin();
	i = 0;
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
	start_write(fmt, begin);
	return (begin->nbr);
}

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
