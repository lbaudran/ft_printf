/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:55:42 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/18 18:55:11 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*print_arg(int *tab, va_list *arg, char *str, const char *format)
{
	char *buffer;
	char *buf;
	int n;
	char	*(*types[16])(va_list *arg, char *buffer, int *tab);

	n = ft_strlen(str);
	buffer = NULL;
	buf = (char *)malloc((n + 1) * sizeof(char));
	ft_strcpy(buf, str);
	init_pt_tab(types);
	buffer = types[tab[7]](arg, buffer, tab);
	free (str);
	buffer = ft_apply_flag(tab, buffer);
	str = (char *) malloc((n + ft_strlen(buffer) + ft_strlen(format) + 1) *
			sizeof (char));
	ft_bzero(str, n + ft_strlen(buffer) + ft_strlen(format) + 1);
	ft_strcpy(str, buf);
	free(buf);
	ft_strcat(str, buffer);
	free(buffer);
	return (str);
}

char		*ft_apply_flag(int *tab, char *buffer)
{
	char	*tmp;
	char	*(*diez[11])(char *tmp, char *buffer, int *tab);

	init_diez_tab(diez);
	if (tab[4] > ft_strlen(buffer))
	{
		tmp = (char *)malloc((tab[4] + 4) * sizeof(char));
		ft_bzero(tmp, tab[4] + 4);
	}
	else
	{
		tmp = (char *)malloc((ft_strlen(buffer) + 4) * sizeof(char));
		ft_bzero(tmp, ft_strlen(buffer) + 4);
	}
	if (tab[1] && ((tab[7] >= 6 && tab[7] <= 10) || tab[7] == 1)
		&& buffer[0] != '-')
		tmp[0] = tab[1];
	if (tab[2])
		if ((tab[7] >= 4 && tab[7] <= 10) || tab[7] == 2)
			tmp = diez[tab[7]](tmp, buffer, tab);
	ft_strcat(tmp, buffer);
	if (tab[4] > ft_strlen(buffer))
		buffer = ft_add_empty(tmp, tab, buffer);
	return(tmp);
}

char		*ft_add_empty(char *tmp, int *tab, char *buffer)
{
	int		n;
	int		i;
	char	tmp2[tab[4] + 1];

	i = 0;
	n = ft_strlen(tmp);
	if (tab[0] != '0')
		tab[3] = ' ';
	else
		tab[3] = '0';
	if (tab[0] == '-')
		while (tab[4] - n)
			tmp[n++] = tab[3];
	else
	{
		ft_bzero(tmp2, tab[4] + 1);
		if ((tmp[0] == '-' || tmp[0] == '+') && tab[3] == '0')
		{
			tmp2[i++] = tmp[0];
			ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
			n--;
		}
		while (i < tab[4] - n)
			tmp2[i++] = tab[3];
		ft_strcat(tmp2, tmp);
		ft_strcpy(tmp, tmp2);
	}
	return(tmp);
}
