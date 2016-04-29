/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:25:48 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/29 15:41:27 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_int(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	char	*(*modif_signed[7])(va_list *arg, char *buffer, int *tab);

	init_signed_tab(modif_signed);
	buffer = modif_signed[tab[6]](arg, buffer, tab);
	if (buffer[0] == '0' && tab[5] == -1)
		buffer[0] = '\0';
	buffer = ft_addzero(buffer, tab);
	return (buffer);
}

char	*get_char(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	wchar_t	c;

	buffer = (char *)malloc(2 * sizeof(char));
	ft_bzero(buffer, 2);
	if (tab[6] != 3)
	{
		c = va_arg((*arg), int);
		buffer[0] = c;
		if (c == '\0')
			elem->aff_null = 1;
		if (elem->aff_null)
			tab[4]--;
		return (buffer);
	}
	free(elem->unicode);
	c = va_arg((*arg), wchar_t);
	if (c == '\0')
		elem->aff_null_w = 1;
	elem->unicode = (wchar_t *)malloc(2 * sizeof(wchar_t));
	elem->unicode[0] = c;
	elem->unicode[1] = '\0';
	if (elem->aff_null_w)
		tab[4]--;
	return (buffer);
}

char	*get_str(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg((*arg), char *);
	if (str)
	{
		buffer = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
		ft_bzero(buffer, ft_strlen(str) + 1);
	}
	else
	{
		buffer = (char *)malloc(7 * sizeof(char));
		str = (char *)malloc(7 * sizeof(char));
		ft_strcpy(str, "(null)\0");
		i++;
	}
	if (tab[5] && str && tab[5] != -1)
		ft_strncpy(buffer, str, tab[5]);
	else if (!tab[5] && str)
		ft_strcpy(buffer, str);
	if (i)
		free(str);
	return (buffer);
}

char	*get_int_ns(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	unsigned int	i;
	char			*(*modif_unsigned[7])(va_list *arg, char *buffer,
			int *tab, int base);

	init_unsigned_tab(modif_unsigned);
	buffer = modif_unsigned[tab[6]](arg, buffer, tab, 10);
	if (buffer[0] == '0' && tab[5] == -1)
		buffer[0] = '\0';
	buffer = ft_addzero(buffer, tab);
	return (buffer);
}

char	*get_octal(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	char	*(*modif_unsigned[7])(va_list *arg, char *buffer, int *tab, int base);
	int		i;

	i = 0;
	init_unsigned_tab(modif_unsigned);
	buffer = modif_unsigned[tab[6]](arg, buffer, tab, 8);
	while (buffer[i] == '0')
		i++;
	if (tab[5] < 0 && buffer[i] == '\0')
		buffer[0] = '\0';
	buffer = ft_addzero(buffer, tab);
	return (buffer);
}
