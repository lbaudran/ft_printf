/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:36:27 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 16:40:09 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_normal_unsigned(va_list *arg, char *buffer, int *tab, int base)
{
	unsigned int	i;

	i = va_arg((*arg), unsigned int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_short_short_unsigned(va_list *arg, char *buffer, int *tab, int base)
{
	unsigned char	i;

	i = va_arg((*arg), unsigned int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_short_unsigned(va_list *arg, char *buffer, int *tab, int base)
{
	unsigned short	i;

	i = va_arg((*arg), unsigned int);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_long_long_unsigned(va_list *arg, char *buffer, int *tab, int base)
{
	unsigned long long	i;

	i = va_arg((*arg), unsigned long long);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char	*get_long_unsigned(va_list *arg, char *buffer, int *tab, int base)
{
	unsigned long	i;

	i = va_arg((*arg), unsigned long);
	buffer = ft_convertbase(i, base);
	return (buffer);
}
