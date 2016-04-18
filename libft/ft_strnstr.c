/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:38:06 by lbaudran          #+#    #+#             */
/*   Updated: 2015/11/28 16:30:50 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str1[i] && str2[j] && i != (int)len)
	{
		while (str1[i] == str2[j] && str1[i] && i != (int)len)
		{
			i++;
			j++;
			if (str2[j] == '\0')
				return ((char *)str1 + i - j);
		}
		i -= j;
		j = 0;
		i++;
	}
	if (str1[i] == '\0' || i == (int)len || str2[j])
		return (NULL);
	else
		return ((char *)str1 + i);
}
