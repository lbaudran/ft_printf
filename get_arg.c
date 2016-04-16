/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:25:48 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/16 17:02:25 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_int(va_list *arg, char *buffer, int *tab)
{
	int			i;
	int			n;
	char		*tmp;

	n = 0;
	i = va_arg((*arg), int);
	buffer = ft_itoa(i);
	if (tab[5] > ft_strlen(buffer))
	{
		tmp = (char *)malloc(tab[5] * sizeof(char));
		while ((tab[5])-- > ft_strlen(buffer))
			tmp[n++] = '0';
		ft_strcat(tmp, buffer);
		return (tmp);
	}
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
	if (tab[5])
		ft_strncpy(buffer, str, tab[5]);
	else
		ft_strcpy(buffer, str);
	return (buffer);

}

char	*get_int_ns(va_list *arg, char *buffer, int *tab)
{
	unsigned int	i;
	char		*tmp;
	int			n;

	n = 0;
	i = va_arg((*arg), unsigned int);
	if (tab[5] > (int)ft_strlen(buffer))
	{
		tmp = (char *)malloc(tab[5] * sizeof(char));
		while ((tab[5])-- > (int)ft_strlen(buffer))
			tmp[n++] = '0';
		ft_strcat(tmp, buffer);
		return (tmp);
	}
	buffer = ft_itoa(i);
	return (buffer);
}

char	*get_octal(va_list *arg, char *buffer, int *tab)
{
	int			i;
	int			n;
	char		*tmp;

	n = 0;
	i = va_arg((*arg), int);
	buffer = ft_convertbase(i, 8);
	if (tab[5] > ft_strlen(buffer))
	{
		tmp = (char *)malloc(tab[5] * sizeof(char));
		while ((tab[5])-- > ft_strlen(buffer))
			tmp[n++] = '0';
		ft_strcat(tmp, buffer);
		return (tmp);
	}
	return (buffer);
}
