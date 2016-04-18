/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:50:25 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/22 16:06:22 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		total;
	char		*dst2;
	const char	*src2;

	i = size;
	dst2 = dst;
	src2 = src;
	while (*dst2 && i--)
		dst2++;
	total = dst2 - dst;
	i = size - total;
	if (!i)
		return (total + ft_strlen(src));
	while (*src2)
	{
		if (i != 1)
		{
			*dst2++ = *src2;
			i--;
		}
		src2++;
	}
	*dst2 = '\0';
	return (total + (src2 - src));
}
