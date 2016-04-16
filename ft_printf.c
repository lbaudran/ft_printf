/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:28:26 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/16 17:43:56 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int 		ft_printf(const char *fmt, ...)
{
	int			a;
	int			i;
	char		*line;
	va_list		ap;

	line = (char *)malloc(ft_strlen(fmt) + 1);
	ft_bzero(line, ft_strlen(fmt) + 1);
	va_start(ap, fmt);
	i = 0;
	a = 0;
	while (fmt[i])
	{
			a = ft_strlen(line);
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
	a = ft_strlen(line);
	free(line);
	return (a);
}

char		*stock_str(va_list *ap, int *i, char *line, const char *fmt)
{
	int				tab[8];

	reset_tab(tab, 8);
	if (fmt[(*i) + 1] == '%')
		check_percent(fmt, i, line);
	if (fmt[(*i)] != '%')
		return (line);
	if (check_start(i, fmt, ap, tab) == -1)
		return (NULL);
	line = print_arg(tab, ap, line, fmt);
	return (line);
}

int	main()
{
	char c = -1;
	char t[2];
	t[0] = c;
	ft_printf("%c aaa\n", NULL);
	printf("%c aaa\n", c);
	printf("%s", t);

}
