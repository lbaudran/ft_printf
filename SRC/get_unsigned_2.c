/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:42:04 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 16:44:48 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*get_unsigned_max(va_list *arg, char *buffer, int *tab, int base)
{
	uintmax_t	i;

	i = va_arg((*arg), uintmax_t);
	buffer = ft_convertbase(i, base);
	return (buffer);
}

char		*get_size_unsigned(va_list *arg, char *buffer, int *tab, int base)
{
	size_t	i;

	i = va_arg((*arg), size_t);
	buffer = ft_convertbase(i, base);
	return (buffer);
}
