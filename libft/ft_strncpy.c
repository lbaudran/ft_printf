/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:55:20 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/16 16:44:00 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int		i;

	i = 0;
	while (src[i] && n)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	while (n > 0)
	{
		dst[i++] = '\0';
		n--;
	}
	return (dst);
}
