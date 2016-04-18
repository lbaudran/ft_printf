/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:46:07 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/14 15:52:27 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*fill_point(char *buffer)
{
	char	tmp[15];
	int		i;
	int		n;

	n = 3;
	ft_bzero(tmp, 15);
	i = ft_strlen(buffer);
	tmp[0] = '0';
	tmp[1] = 'x';
	if (i++ < 12)
	{
		tmp[2] = '7';
		while (i++ < 12)
			tmp[n++] = 'f';
	}
	ft_strcat(tmp, buffer);
	free(buffer);
	buffer = (char *)malloc(15 * sizeof(char));
	ft_bzero(buffer, 15);
	ft_strcpy(buffer, tmp);
	return (buffer);
}
