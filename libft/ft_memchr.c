/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:46:06 by lbaudran          #+#    #+#             */
/*   Updated: 2015/11/28 16:39:29 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*str2;

	str2 = str;
	while (n && (*str2 != (unsigned char)c))
	{
		n--;
		str2++;
	}
	if (n)
		return ((void *)str2);
	else
		return (NULL);
}
