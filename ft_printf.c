/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:28:26 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/18 19:14:29 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

int			ft_putprintf(char *line)
{
	int		a;

	a = 0;
	while (line[a])
	{
		if (line[a] == -127)
			line[a] = 0;
		write(1, &line[a], 1);
		a++;
	}
	return(a);
}


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
	a = ft_putprintf(line);
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
/*
int	main()
{
	int	i = 1;
	char c = -1;
	char t[2];
	t[0] = c;
	char	w = (char)-127;
	ft_printf("%.0000000010i\n", -i);
	printf("%.00000000010i\n", -i);

}*/
