/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 19:25:48 by lbaudran          #+#    #+#             */
/*   Updated: 2016/04/20 17:14:03 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_int(va_list *arg, char *buffer, int *tab)
{
	int			i;
	int			n;
	char		*tmp;
	int			y;

	y = tab[5];
	n = 0;
	i = va_arg((*arg), int);
	buffer = ft_itoa(i);
	if (buffer[0] == '0' && tab[5] == -1)
		buffer[0] = '\0';
	if (tab[5] > (int)ft_strlen(buffer))
	{
		tmp = (char *)malloc(tab[5] * sizeof(char));
		if (buffer[0] == '-' || buffer[0] == '+')
		{
			tmp[n++] = buffer[0];
			ft_memmove(buffer, buffer + 1, ft_strlen(buffer));
		}
		while (y-- > ft_strlen(buffer))
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
	if (c != 0)
	buffer[0] = c;
	else
		buffer[0] = 129;
	buffer[1] = '\0';
	return (buffer);
}

char	*get_str(va_list *arg, char *buffer, int *tab)
{
	char *str;

	str = va_arg((*arg), char *);
	if (str)
	{
		buffer = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
		ft_bzero(buffer, ft_strlen(str) + 1);
	}
	else{
		buffer = (char *)malloc(7);
		ft_strcpy(buffer, "(null)\0");}
	if (tab[5] && str)
		ft_strncpy(buffer, str, tab[5]);
	else if (!tab[5] && str)
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
	buffer = ft_utoa(i);
	if (buffer[0] == '0' && tab[5] == -1)
		buffer[0] = '\0';
	if (tab[5] > (int)ft_strlen(buffer))
	{
		tmp = (char *)malloc(tab[5] * sizeof(char));
		while ((tab[5])-- > (int)ft_strlen(buffer))
			tmp[n++] = '0';
		ft_strcat(tmp, buffer);
		return (tmp);
	}
	return (buffer);
}

char	*get_octal(va_list *arg, char *buffer, int *tab)
{
	unsigned int			i;
	int						n;
	char					*tmp;

	n = 0;
	//buffer = 
	i = va_arg((*arg), unsigned int);
	buffer = ft_convertbase(i, 8);
	if (buffer[0] && tab[5] == -1)
		buffer[0] = '\0';
	if (tab[5] > (int)ft_strlen(buffer))
	{
		tmp = (char *)malloc(tab[5] * sizeof(char));
		while ((tab[5])-- > ft_strlen(buffer))
			tmp[n++] = '0';
		ft_strcat(tmp, buffer);
		return (tmp);
	}
	return (buffer);
}
