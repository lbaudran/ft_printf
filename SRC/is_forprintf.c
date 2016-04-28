/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_forprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:28:06 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/28 16:50:35 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				is_noargforprintf(char c)
{
	if (c == '.' || c == '+' || c == '-' || c == '#' || c == ' ' || c == 'l' ||
		c == 'L' || c == 'h' || c == 'j' || c == 'z' || c == '*')
		return (1);
	else if (ft_isdigit(c))
		return (1);
	return (0);
}

int				is_intforprintf(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
		c == 'f' || c == 'e' || c == 'E' || c == 'g' || c == 'G' || c == 'p' ||
		c == 'c')
		return (1);
	return (0);
}

int				is_typeforprintf(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
		c == 'f' || c == 'e' || c == 'E' || c == 'g' || c == 'G' || c == 'c' ||
		c == 's' || c == 'p' || c == 'b' || c == 'B' || c == 'D' || c == 'I' ||
		c == 'O' || c == 'U' || c == '%' || c == 'F' || c == 'C' || c == 'S')
		return (1);
	return (0);
}

void			reset_tab(int *tab, int i)
{
	int		n;

	n = 0;
	while (n <= i)
		tab[n++] = 0;
	tab[3] = ' ';
}

int				is_check(char c)
{
	if (is_typeforprintf(c))
		return (1);
	if (is_noargforprintf(c))
		return (1);
	return (0);
}
