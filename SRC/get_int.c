/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:20:15 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 16:36:13 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*get_normal_int(va_list *arg, char *buffer, int *tab)
{
	int	i;

	i = va_arg((*arg), int);
	buffer = ft_itoa(i);
	return (buffer);
}

char		*get_short_short_int(va_list *arg, char *buffer, int *tab)
{
	signed char	i;

	i = va_arg((*arg), int);
	buffer = ft_itoa(i);
	return (buffer);
}

char		*get_short_int(va_list *arg, char *buffer, int *tab)
{
	short	i;

	i = va_arg((*arg), int);
	buffer = ft_itoa(i);
	return (buffer);
}

char		*get_long_int(va_list *arg, char *buffer, int *tab)
{
	long	i;

	i = va_arg((*arg), long);
	buffer = ft_itoa(i);
	return (buffer);
}

char		*get_long_long_int(va_list *arg, char *buffer, int *tab)
{
	long long	i;

	i = va_arg((*arg), long long);
	buffer = ft_itoa(i);
	return (buffer);
}
