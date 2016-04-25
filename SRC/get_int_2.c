/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:32:17 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 17:51:01 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*get_int_max(va_list *arg, char* buffer, int *tab)
{
	intmax_t	i;

	i = va_arg((*arg), intmax_t);
	buffer = ft_itoa(i);
	return (buffer);
}

char		*get_size_int(va_list *arg, char *buffer, int *tab)
{
	size_t	i;

	i = va_arg((*arg), size_t);
	buffer = ft_itoa(i);
	return (buffer);
}
