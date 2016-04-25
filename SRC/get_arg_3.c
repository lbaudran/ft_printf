/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:19:07 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 18:49:09 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*get_point(va_list *arg, char *buffer, int *tab)
{
	long		i;

	i = va_arg((*arg), long);
	buffer = ft_convertbase(i, 16);
	buffer = fill_point(buffer);
	return (buffer);
}

char		*get_shorter(va_list *arg, char *buffer, int *tab)
{
	double	i;
	int		n;
	double	y;
	int		a;

	n = 0;
	i = va_arg((*arg), double);
	y = i;
	if (!tab[5])
		tab[5] = 6;
	else if (tab[5] == -1)
		tab[5] = 1;
	if (y)
		n = size_forscient(&y);
	if (n <= tab[5] - 1)
		buffer = ft_dtoa(i, tab[5] - 1 - n);
	else
		buffer = ft_dtoa(i, tab[5] - 1);
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	a = ft_strlen(buffer) - 1;
	ft_add_nul(buffer, a);
	if (n > tab[5])
		buffer = arg_forscient(buffer, n);
	return (buffer);
}

char		*get_shorter_up(va_list *arg, char *buffer, int *tab)
{
	int		n;

	n = 0;
	buffer = get_shorter(arg, buffer, tab);
	while (buffer[n])
	{
		buffer[n] = ft_toupper(buffer[n]);
		n++;
	}
	return (buffer);
}

char		*get_binary(va_list *arg, char *buffer, int *tab)
{
	int		i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 2);
	return (buffer);
}
