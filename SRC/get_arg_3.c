/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:19:07 by lbaudran          #+#    #+#             */
/*   Updated: 2016/05/02 15:48:21 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*get_point(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	long		i;

	i = va_arg((*arg), long);
	buffer = ft_convertbase(i, 16);
	i = 0;
	while (buffer[i] == '0')
		i++;
	if (tab[5] == -1 && buffer[i] == '\0')
		buffer[0] = '\0';
	buffer = ft_addzero(buffer, tab);
	buffer = fill_point(buffer);
	return (buffer);
}

char		*get_shorter(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	double	i;
	int		n;
	double	y;
	int		a;

	n = 0;
	i = va_arg((*arg), double);
	y = i;
	if (!tab[5])
		tab[5] = 6;
	else if (tab[5] == -1)
		tab[5] = 1;
	if (y)
		n = size_forscient_normal(&y);
	if (n <= tab[5] - 1)
		buffer = ft_dtoa(i, tab[5] - 1 - n);
	else
		buffer = ft_dtoa(i, tab[5] - 1);
	buffer = ft_round(buffer, ft_strlen(buffer) - 1);
	a = ft_strlen(buffer) - 1;
	ft_add_nul(buffer, a);
	if (n > tab[5])
		buffer = arg_forscient(buffer, n);
	return (buffer);
}

char		*get_shorter_up(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	int		n;

	n = 0;
	buffer = get_shorter(arg, buffer, tab, elem);
	while (buffer[n])
	{
		buffer[n] = ft_toupper(buffer[n]);
		n++;
	}
	return (buffer);
}

char		*get_binary(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	int		i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 2);
	return (buffer);
}

char		*get_wstring(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	wchar_t	*t;
	int		i;

	free(elem->unicode);
	if (tab[5] == 0)
		tab[5] = -1;
	else if (tab[5] == -1)
		tab[5] = 0;
	buffer = malloc(1 * sizeof(char));
	t = va_arg((*arg), wchar_t *);
	if (t)
	{
		elem->unicode = malloc((ft_wstrlen(t) + 1) * sizeof(wchar_t));
		ft_bzero(elem->unicode, ft_wstrlen(t) + 1);
		ft_wstrcpy(elem->unicode, t);
	}
	else
	{
		elem->unicode = (wchar_t *)malloc(7 * sizeof(wchar_t));
		ft_wstrcpy(elem->unicode, L"(null)\0");
	}
	if (tab[5] >= 0)
		apply_acc_wchar(elem, tab);
	return (buffer);
}
