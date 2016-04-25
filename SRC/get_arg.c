/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:25:48 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 19:43:48 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_int(va_list *arg, char *buffer, int *tab)
{
	char	*(*modif_signed[7])(va_list *arg, char *buffer, int *tab);

	init_signed_tab(modif_signed);
	buffer = modif_signed[tab[6]](arg,buffer, tab);
	if (buffer[0] == '0' && tab[5] == -1)
		buffer[0] = '\0';
	buffer = ft_addzero(buffer, tab);
	return (buffer);
}

char	*get_char(va_list *arg, char *buffer, int *tab)
{
	char	c;

	c = va_arg((*arg), int);
	buffer = (char *)(malloc(2 * sizeof(char)));
	if (c == 0)
		c = -127;
	buffer[0] = c;
	buffer[1] = '\0';
	return (buffer);
}

char	*get_str(va_list *arg, char *buffer, int *tab)
{
	char *str;

	str = va_arg((*arg), char *);
	if (str)
	{
		buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
		ft_bzero(buffer, ft_strlen(str) + 1);
	}
	else
	{
		buffer = (char *)malloc(7 * sizeof(char));
		ft_strcpy(buffer, "(null)\0");
	}
	if (tab[5] && str && tab[5] != -1)
		ft_strncpy(buffer, str, tab[5]);
	else if (!tab[5] && str)
		ft_strcpy(buffer, str);
	return (buffer);
}

char	*get_int_ns(va_list *arg, char *buffer, int *tab)
{
	unsigned int	i;
	char *(*modif_unsigned[7])(va_list *arg, char *buffer, int *tab, int base);

	init_unsigned_tab(modif_unsigned);
	buffer = modif_unsigned[tab[6]](arg, buffer, tab, 10);
	if (buffer[0] == '0' && tab[5] == -1)
		buffer[0] = '\0';
	buffer = ft_addzero(buffer, tab);
	return (buffer);
}

char	*get_octal(va_list *arg, char *buffer, int *tab)
{
	char	*(*modif_unsigned[7])(va_list *arg, char *buffer, int *tab, int base);

	init_unsigned_tab(modif_unsigned);
	buffer = modif_unsigned[tab[6]](arg, buffer, tab, 8);
	if (buffer[0] && tab[5] == -1)
		buffer[0] = '\0';
	buffer = ft_addzero(buffer, tab);
	return (buffer);
}
