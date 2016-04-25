/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 16:35:36 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 17:45:14 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*get_hexa_low(va_list *arg, char *buffer, int *tab)
{
	unsigned int		i;
	char	*(*modif_unsigned[7])(va_list *arg, char *buffer, int *tab, int base);

	init_unsigned_tab(modif_unsigned);
	buffer = modif_unsigned[tab[6]](arg, buffer, tab, 16);
	if (buffer[0] == '0' && tab[5] == -1)
		buffer[0] = '\0';
	buffer = ft_addzero(buffer, tab);
	return (buffer);
}

char	*get_hexa_up(va_list *arg, char *buffer, int *tab)
{
	int		i;
	char	*(*modif_unsigned[7])(va_list *arg, char *buffer, int *tab, int base);

	i = 0;
	init_unsigned_tab(modif_unsigned);
	buffer = modif_unsigned[tab[6]](arg, buffer, tab, 16);
	while (buffer[i])
	{
		buffer[i] = ft_toupper(buffer[i]);
		i++;
	}
	if (buffer[0] == '0' && tab[5] == -1)
		buffer[0] = '\0';
	buffer = ft_addzero(buffer, tab);
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
	return (buffer);
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
	return (buffer);
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
	return (buffer);
}
