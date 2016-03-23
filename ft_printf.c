/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:28:26 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/23 16:10:02 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

t_list			*create_begin(void)
{
	t_list	*begin;
	begin = (t_list*)malloc(sizeof(t_list));
	begin->next = NULL;
	begin->str = NULL;
	begin->nbr = 0;
	begin->use = 0;
	begin->tab = (int *)malloc(5);
	return (begin);
}

void			create_list(t_list *begin,char c, char *s)
{
	t_list	*elem;

	elem = begin;
	if (is_intforprintf(c))
	{
		elem->next = (t_list*)malloc(sizeof(t_list));
		elem->next->use = 0;
		elem->next->nbr = ft_atoi(s);

	}
}
void			stock_arg(t_list *begin, char c, char *s)
{
	if (c == 's')
		create_list(begin, s);
	else if (is_intforprintf(c))
		create_list(begin, ft_atoi(s));

}
int 			ft_printf(const char *format, ...)
{
	int			y;
	int			i;
	t_list		*begin;
	va_list		ap;

	begin = create_begin(void);
	i = 0;
	while (format[i++])
	{
		if (format[i] == '%')
		{
			y = 1;
			while (format[i - y] == '\\')
				y++;
			if (y % 2 == 1)
			{
				i++;
				while (is_noargforprintf(format[i]))
					i++;
				if (is_intforprintf(format[i]) || format[i] == '*')
					create_list(begin, format[i++],ft_itoa(va_arg(ap, int)));
				else if (format[i] == 's')
					create_list(begin, format[i++],va_arg(ap, char *));
			}
		}
	}
	
	return (begin->compt);
}

void			start_write(const char* format)
{
	int		i;
	int		n;
	int		y;
	va_list ap;
	t_list	*begin;

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
				n = check_start(i, format, begin);
			else
				ft_putchar(format[i++]);
		}
		else
			ft_putchar(format[i++]);
	}
		return(i - n);
}
