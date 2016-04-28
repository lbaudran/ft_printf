/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:42:00 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/28 18:19:12 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_dtoa(long double i, int size)
{
	int				u;
	char			*str;
	char			*buffer;

	buffer = ft_itoa((long int)i);
	str = (char *)malloc((ft_strlen(buffer) + size + 3) * sizeof(char));
	ft_bzero(str, ft_strlen(buffer) + size + 3);
	ft_strcpy(str, buffer);
	free(buffer);
	u = ft_strlen(str);
	str[u++] = '.';
	i = i - (long double)(long int)i;
	if (i < 0)
		i = -i;
	while (size-- + 1)
	{
		i = 10 * i;
		str[u++] = (int)i + '0';
		i = i - (long double)(int)i;
	}
	if (str[ft_strlen(str) - 2] == '.' && str[ft_strlen(str) - 1] == '0')
		str[ft_strlen(str) - 1] = '\0';
	return (str);
}
