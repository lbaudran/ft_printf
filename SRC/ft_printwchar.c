/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:11:18 by lbaudran          #+#    #+#             */
/*   Updated: 2016/05/02 15:17:07 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_size_octet(wchar_t c)
{
	int		i;

	i = ft_size_bits(c);
	if (i <= 7)
		return (1);
	if (i <= 11)
		return (2);
	if (i <= 16)
		return (3);
	return (4);
}

void		apply_acc_wchar(t_list *elem, int *tab)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (n <= tab[5] && elem->unicode[i])
	{
		n += ft_size_octet(elem->unicode[i]);
		if (n > tab[5])
			elem->unicode[i] = '\0';
		i++;
	}
}

int			ft_size_bits(wchar_t c)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_convertbase(c, 2);
	i = ft_strlen(tmp);
	free(tmp);
	return (i);
}

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void		ft_printwchar(wchar_t c, t_list *elem)
{
	if (c <= 0x7F)
	{
		elem->index += ft_putchar(c);
	}
	else if (c <= 0x7FF)
	{
		elem->index += ft_putchar((c >> 6) + 0xC0);
		elem->index += ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		elem->index += ft_putchar((c >> 12) + 0xE0);
		elem->index += ft_putchar(((c >> 6) & 0x3F) + 0x80);
		elem->index += ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		elem->index += ft_putchar((c >> 18) + 0xF0);
		elem->index += ft_putchar(((c >> 12) & 0x3F) + 0x80);
		elem->index += ft_putchar(((c >> 6) & 0x3F) + 0x80);
		elem->index += ft_putchar((c & 0x3F) + 0x80);
	}
}
