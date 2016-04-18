/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:11:35 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/17 15:54:32 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	int		j;
	char	*n;

	n = (char *)str1;
	i = 0;
	j = 0;
	if (!*str2)
		return ((char *)str1);
	while (str1[i])
	{
		while (str1[i + j] == str2[j] && str2[j])
			j++;
		if (str2[j] == '\0')
			return ((char *)str1 + i);
		j = 0;
		i++;
	}
	return (NULL);
}
