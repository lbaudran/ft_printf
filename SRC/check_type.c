/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:32:59 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/26 15:47:24 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_type_2(int *tab, char c)
{
	if (c == 'g')
		tab[7] = 9;
	if (c == 'G')
		tab[7] = 10;
	if (c == 'c' || c == 'C')
		tab[7] = 11;
	if (c == 's' || c == 'S')
		tab[7] = 12;
	if (c == 'p')
		tab[7] = 13;
	if (c == 'b' || c == 'B')
		tab[7] = 14;
	if (c == '%')
		tab[7] = 15;
	if (c == 'x')
		tab[7] = 4;
	if (c == 'X')
		tab[7] = 5;
	if (c == 'f' || c == 'F')
		tab[7] = 6;
	if (c == 'e')
		tab[7] = 7;
	if (c == 'E')
		tab[7] = 8;
}

int		check_type(int *tab, char c)
{
	if (c == 'd' || c == 'i' || c == 'D' || c == 'I')
	{
		tab[7] = 1;
		if (c == 'D' || c == 'I')
			tab[6] = 3;
	}
	if (c == 'o' || c == 'O')
	{
		tab[7] = 2;
		if (c == 'O')
			tab[6] = 3;
	}
	if (c == 'u' || c == 'U')
	{
		tab[7] = 3;
		if (c == 'U')
			tab[6] = 3;
	}
	check_type_2(tab, c);
	if (tab[7])
		return (1);
	return (-1);
}

char		*check_percent(va_list *arg, char *buffer, int *tab)
{
	buffer = (char *)malloc(2 * sizeof(char));
	buffer[0] = '%';
	buffer[1] = '\0';
	return (buffer);
}
