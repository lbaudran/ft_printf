/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:55:30 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/17 12:40:54 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nbrchiff(int n)
{
	int		i;

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

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;

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
