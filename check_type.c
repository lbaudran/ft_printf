/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 18:32:59 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/14 14:58:08 by lbaudran         ###   ########.fr       */
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
}

int		check_type(int *tab, char c)
{
	if (c == 'd' || c == 'i' || c == 'D' || c == 'I')
		tab[7] = 1;
	if (c == 'o' || c == 'O')
		tab[7] = 2;
	if (c == 'u' || c == 'U')
		tab[7] = 3;
	if (c == 'x')
		tab[7] = 4;
	if (c == 'X')
		tab[7] = 5;
	if (c == 'f')
		tab[7] = 6;
	if (c == 'e')
		tab[7] = 7;
	if (c == 'E')
		tab[7] = 8;
	check_type_2(tab, c);
	if (tab[7])
		return (1);
	return (-1);
}
