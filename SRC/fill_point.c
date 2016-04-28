/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:46:07 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/28 18:20:46 by lbaudran         ###   ########.fr       */
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
	ft_strcat(tmp, buffer);
	free(buffer);
	buffer = (char *)malloc(15 * sizeof(char));
	ft_bzero(buffer, 15);
	ft_strcpy(buffer, tmp);
	return (buffer);
}

void		ft_add_nul(char *buffer, int a)
{
	while (buffer[a] == '0')
		buffer[a--] = '\0';
	if (buffer[a] == '.')
		buffer[a] = '\0';
}

char		*ft_addzero(char *buffer, int *tab)
{
	int		n;
	int		y;
	char	tmp[tab[5] + 1];

	ft_bzero(tmp, tab[5] + 1);
	y = tab[5];
	n = 0;
	if (tab[5] > (int)ft_strlen(buffer))
	{
		if (buffer[0] == '-' || buffer[0] == '+')
		{
			tmp[n++] = buffer[0];
			ft_memmove(buffer, buffer + 1, ft_strlen(buffer));
		}
		while (y-- > ft_strlen(buffer))
			tmp[n++] = '0';
		ft_strcat(tmp, buffer);
		free(buffer);
		buffer = (char *)malloc((tab[5] + 2) * sizeof(char));
		ft_bzero(buffer, tab[5] + 2);
		ft_strcpy(buffer, tmp);
	}
	return (buffer);
}
