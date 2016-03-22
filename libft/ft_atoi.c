/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:10:53 by lbaudran          #+#    #+#             */
/*   Updated: 2015/11/27 21:46:06 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int		value;
	int		signe;

	signe = 1;
	value = 0;
	while (*s == ' ' || *s == '\n' || *s == '\v' || *s == '\f' || *s == '\t'
			|| *s == '\r')
		s++;
	while (*s < 1 && *s > 9 && *s != '-' && *s != '+' && *s)
		s++;
	if (*s == '-')
	{
		s++;
		signe = -1;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		value = value * 10 + (*s - '0');
		s++;
	}
	return (value * signe);
}
