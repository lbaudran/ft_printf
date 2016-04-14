/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:35:36 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/14 16:30:58 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*get_hexa_low(va_list *arg, char *buffer, int *tab)
{
	int		i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 16);
	return (buffer);
}

char	*get_hexa_up(va_list *arg, char *buffer, int *tab)
{
	int		i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 16);
	i = 0;
	while (buffer[i])
	{
		buffer[i] = ft_toupper(buffer[i]);
		i++;
	}
	return (buffer);
}

char	*get_double(va_list *arg, char *buffer, int *tab)
{
	double	i;

	i = va_arg((*arg), double);
	buffer = ft_dtoa(i, 6);
	buffer = ft_round(buffer, (ft_strlen(buffer) - 1));
	return(buffer);
}

char	*get_scient(va_list *arg, char *buffer, int *tab)
{
	double	i;
	int		n;

	n = 0;
	i = va_arg((*arg), double);
	if (i)
		n = size_forscient(&i);
	buffer = ft_dtoa(i, 6);
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = arg_forscient(buffer, n);
	return(buffer);
}

char	*get_scient_up(va_list *arg, char *buffer, int *tab)
{
	double	i;
	int		n;

	n = 0;
	i = va_arg((*arg), double);
	if (i)
		n = size_forscient(&i);
	buffer = ft_dtoa(i, 6);
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = arg_forscient_up(buffer, n);
	return(buffer);
}
