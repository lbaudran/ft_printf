/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_forprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:28:06 by lbaudran          #+#    #+#             */
/*   Updated: 2016/03/23 15:28:43 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				is_noargforprintf(char c)
{
	if (c == '.' || c == '+' || c == '-' || c == '#' || c == ' ' || c == 'l' ||
		c == 'L' || c == 'h')
		return (1);
	else if (ft_isdigit(c))
		return (1);
	return (0);
}

int 			is_intforprintf(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X' ||
		c == 'f' || c == 'e' || c == 'E' || c == 'g' || c == 'G' || c == 'p' ||
		c == 'c')
		return (1);
	return (0);
}