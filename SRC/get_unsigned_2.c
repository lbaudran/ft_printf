/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:42:04 by lbaudran          #+#    #+#             */
/*   Updated: 2016/05/02 15:54:21 by lbaudran         ###   ########.fr       */
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

void		acc_reduct(const char *s, int *i, int *tab)
{
	char	tmp[19];
	int		n;

	n = 0;
	ft_bzero(tmp, 19);
	while (s[*i] >= '0' && s[*i] <= '9')
		tmp[n++] = s[(*i)++];
	tab[5] = ft_atoi(tmp);
}
