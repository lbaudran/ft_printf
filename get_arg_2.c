/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:35:36 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/19 18:07:07 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*get_hexa_low(va_list *arg, char *buffer, int *tab)
{
	int		i;
	int		n;
	char	*tmp;

	n = 0;
	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 16);
	if (buffer[0] == '0' && tab[5] == -1)
		buffer[0] = '\0';
	if (tab[5] > (int)ft_strlen(buffer))
	{
		tmp = (char *)malloc(tab[5] * sizeof(char));
		while ((tab[5])-- > ft_strlen(buffer))
			tmp[n++] = '0';
		ft_strcat(tmp, buffer);
		return (tmp);
	}
	return (buffer);
}

char	*get_hexa_up(va_list *arg, char *buffer, int *tab)
{
	int		i;
	int		n;
	char	*tmp;

	n = 0;
	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 16);
	i = 0;
	while (buffer[i])
	{
		buffer[i] = ft_toupper(buffer[i]);
		i++;
	}
	if (buffer[0] == '0' && tab[5] == -1)
		buffer[0] = '\0';
	if (tab[5] > (int)ft_strlen(buffer))
	{
		tmp = (char *)malloc(tab[5] * sizeof(char));
		while ((tab[5])-- > ft_strlen(buffer))
			tmp[n++] = '0';
		ft_strcat(tmp, buffer);
		return (tmp);
	}
	return (buffer);
}

char	*get_double(va_list *arg, char *buffer, int *tab)
{
	double	i;

	if (tab[5] == 0)
		tab[5] = 6;
	i = va_arg((*arg), double);
	buffer = ft_dtoa(i, tab[5]);
	buffer = ft_round(buffer, (ft_strlen(buffer) - 1));
	return(buffer);
}

char	*get_scient(va_list *arg, char *buffer, int *tab)
{
	double	i;
	int		n;

	n = 0;
	i = va_arg((*arg), double);
	if (tab[5] == 0)
		tab[5] = 6;
	if (i)
		n = size_forscient(&i);
	buffer = ft_dtoa(i, tab[5]);
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = arg_forscient(buffer, n);
	return(buffer);
}

char	*get_scient_up(va_list *arg, char *buffer, int *tab)
{
	double	i;
	int		n;

	n = 0;
	i = va_arg((*arg), double);
	if (tab[5] == 0)
		tab[5] = 6;
	if (i)
		n = size_forscient(&i);
	buffer = ft_dtoa(i, tab[5]);
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	buffer = arg_forscient_up(buffer, n);
	return(buffer);
}
