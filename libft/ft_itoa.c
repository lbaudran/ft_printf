/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:55:30 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 18:29:14 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/libftprintf.h"
#include <stdlib.h>

static long	ft_nbrchiff(long n)
{
	long		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long n)
{
	char					*str;
	long					i;
	unsigned long			nb;

	i = ft_nbrchiff(n);
	nb = n;
	if (n < 0)
		i++;
	str = (void *)malloc(i + 1);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	str[i] = '\0';
	i--;
	while (nb > 9)
	{
		str[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	str[i] = nb + '0';
	return (str);
}
