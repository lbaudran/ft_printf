/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:25:48 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/14 18:49:43 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_int(va_list *arg, char *buffer, int *tab)
{
	intmax_t i;
	i = va_arg((*arg), intmax_t);
	buffer = ft_itoa(i);
	return (buffer);
}

char	*get_char(va_list *arg, char *buffer, int *tab)
{
	char c;

	c = va_arg((*arg), int);
	buffer = (char *)(malloc(2 * sizeof(char)));
	buffer[0] = c;
	buffer[1] = '\0';
	return (buffer);
}

char	*get_str(va_list *arg, char *buffer, int *tab)
{
	char *str;

	str = va_arg((*arg), char *);
	buffer = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_bzero(buffer, ft_strlen(str) + 1);
	ft_strcpy(buffer, str);
	return (buffer);

}

char	*get_int_ns(va_list *arg, char *buffer, int *tab)
{
	uintmax_t i;

	i = va_arg((*arg), uintmax_t);
	buffer = ft_itoa(i);
	return (buffer);
}

char	*get_octal(va_list *arg, char *buffer, int *tab)
{
	int i;

	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 8);
	return (buffer);
}
