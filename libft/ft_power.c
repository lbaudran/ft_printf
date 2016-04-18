/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:09:32 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/13 18:05:22 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long double		ft_power(long a, int b)
{
	long double c;

	if (b == 0)
		return (1);
	c = a;
	while (b-- > 1)
		c *= a;
	if (b < 0)
		c = 1 / ft_power(a, -b);
	return (c);
}
