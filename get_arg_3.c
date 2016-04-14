/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:19:07 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/14 18:03:02 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*get_point(va_list *arg, char *buffer, int *tab)
{
	int		i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 16);
	buffer = fill_point(buffer);
	return (buffer);
}

char		*get_shorter(va_list *arg, char *buffer, int *tab)
{
	double	i;
	int		n;
	double	y;

	n = 0;
	i = va_arg((*arg), double);
	y = i;
	if (y)
		n = size_forscient(&y);
	if (n > 6)
	{
		buffer = ft_dtoa(y, 6);
		buffer = ft_round(buffer, ft_strlen(buffer) - 1);
		buffer = arg_forscient(buffer, n);
		return (buffer);
	}
	buffer = ft_dtoa(i, 5 - n);
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	return(buffer);
}

char		*get_shorter_up(va_list *arg, char *buffer, int *tab)
{
	int		n;

	n = 0;
	buffer = get_shorter(arg, buffer, tab);
	while(buffer[n])
		ft_toupper(buffer[n++]);
	return (buffer);
}

char		*get_binary(va_list *arg, char *buffer, int *tab)
{
	int		i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 2);
	return (buffer);
}
