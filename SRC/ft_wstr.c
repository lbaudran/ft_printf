/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:21:02 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/28 18:07:11 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_wstrncpy(wchar_t *wstr, wchar_t *src, int i)
{
	int	n;

	n = 0;
	while (src[n] && i)
	{
		wstr[n] = src[n];
		i++;
		n--;
	}
	while (n > 0)
	{
		wstr[n++] = '\0';
		i++;
	}
}

void		ft_wstrcpy(wchar_t *wstr, wchar_t *src)
{
	int	n;

	n = 0;
	while (src[n])
	{
		wstr[n] = src[n];
		n++;
	}
	wstr[n] = '\0';
}

int			ft_wstrlen(wchar_t *wstr)
{
	int	i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}
