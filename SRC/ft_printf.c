/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:28:26 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/27 19:08:22 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_clear_struct(t_list *elem)
{
	free(elem->line);
	free(elem->unicode);
}

t_list		*create_struct(const char *fmt)
{
	t_list		*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	elem->index = 0;
	elem->line = (char *)malloc((ft_strlen(fmt) + 1) * sizeof(char));
	elem->unicode = (wchar_t *)malloc((ft_strlen(fmt) + 1)* sizeof(wchar_t *));
	ft_bzero(elem->line, ft_strlen(fmt) + 1);
	ft_bzero(elem->unicode, ft_strlen(fmt) + 1);
	return (elem);
}

void			ft_putprintf(int *tab, t_list *elem)
{
	int		i;

	i = 0;
	elem->index += write(1, elem->line, ft_strlen(elem->line));
	ft_bzero(elem->line, ft_strlen(elem->line));
	while (elem->unicode[i])
	{
		if (elem->unicode[i] <= 0x7F)
			write(1, &elem->unicode[i], 1);
		else if (elem->unicode[i] <= 0x7FF)
			write(1, &elem->unicode[i], 2);
		else if (elem->unicode[i] <= 0xFFFF)
			write(1, &elem->unicode[i], 3);
		else if (elem->unicode[i] <= 0x10FFFF)
			write(1, &elem->unicode[i], 4);
		i++;
		(elem->index)++;
	}
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
/*
int	main()
{
	int	i;
	char c = -1;
	char *t;
	t = "%5.0x";
	char	w = (char)-127;
	i = printf("%Le\n", (long double)-1);
//	printf("%d\n" , i);
	i = ft_printf("%Le\n", (long double)-1);
//	printf("%d\n" , i);
	//printf("@moulitest: %5.x", t, 0, 0);
}*/
