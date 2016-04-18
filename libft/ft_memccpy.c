/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:53:14 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/16 12:51:49 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp = (char *)src;
	tmp2 = (char *)dst;
	while (n--)
	{
		if (*tmp == c)
		{
			*tmp2++ = *tmp++;
			return (tmp2);
		}
		*tmp2++ = *tmp++;
	}
	return (NULL);
}
