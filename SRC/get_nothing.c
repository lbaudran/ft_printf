/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nothing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 19:01:45 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/25 19:13:23 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_nothing(va_list *arg, char *buffer, int *tab)
{
	buffer = (char *)malloc(1 * sizeof(char));
	buffer[0] = '\0';
	tab[4] -= 1;
	return (buffer);
}
