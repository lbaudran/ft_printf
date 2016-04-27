/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nothing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 19:01:45 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/26 18:01:05 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_nothing(va_list *arg, char *buffer, int *tab)
{
	buffer = (char *)malloc(2 * sizeof(char));
	buffer[0] = tab[8];
	buffer[1] = '\0';
	return (buffer);
}
