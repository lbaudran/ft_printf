/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:21:33 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 17:13:04 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/libftprintf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp = (char *)src;
	tmp2 = (char *)dst;
	while (n--)
	{
		tmp2[i] = tmp[i];
		i++;
	}
	return ((void *)tmp2);
}
