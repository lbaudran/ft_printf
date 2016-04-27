/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:55:42 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/27 19:11:54 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*print_arg(int *tab, va_list *arg, t_list *elem, const char *fmt)
{
	char			*buffer;
	char			*buf;
	int				n;
	char			*(*types[16])(va_list *arg, char *buffer, int *tab);

	n = ft_strlen(elem->line);
	buf = (char *)malloc((n + 1) * sizeof(char));
	ft_strcpy(buf, elem->line);
	init_pt_tab(types);
	buffer = types[tab[7]](arg, buffer, tab);
	free(elem->line);
		buffer = ft_apply_flag(tab, buffer);
//	else
//		ft_apply_flag_unicode(tab, elem);
	elem->line = (char *)malloc((n + ft_strlen(buffer) + ft_strlen(fmt) + 1) *
			sizeof(char));
	ft_bzero(elem->line, n + ft_strlen(buffer) + ft_strlen(fmt) + 1);
	ft_strcpy(elem->line, buf);
	free(buf);
	ft_strcat(elem->line, buffer);
	free(buffer);
	ft_putprintf(tab, elem);
	return (elem->line);
}

char		*ft_apply_flag_2(int *t, char *buf, char *tmp)
{
	char	*(*diez[11])(char *tmp, char *buffer, int *tab);

	init_diez_tab(diez);
	if (t[1] && ((t[7] >= 6 && t[7] <= 10) || t[7] == 1) && buf[0] != '-')
		tmp[0] = t[1];
	if (t[2] && ((t[7] >= 4 && t[7] <= 10) || t[7] == 2 || t[7] == 14))
		buf = diez[t[7]](tmp, buf, t);
	ft_strcat(tmp, buf);
	if (t[4] > (int)ft_strlen(buf))
		tmp = ft_add_empty(tmp, t, buf);
	free(buf);
	return(tmp);
}

char		*ft_apply_flag(int *t, char *buf)
{
	char	*tmp;

	if (t[4] > t[5] && t[5] != 0 && buf[0] != '-' &&
			((t[7] && t[7] < 11) || t[7] == 13))
		t[3] = ' ';
	if (t[4] > ft_strlen(buf))
	{
		tmp = (char *)malloc((t[4] + 4) * sizeof(char));
		ft_bzero(tmp, t[4] + 4);
	}
	else
	{
		tmp = (char *)malloc((ft_strlen(buf) + 4) * sizeof(char));
		ft_bzero(tmp, ft_strlen(buf) + 4);
	}
	tmp = ft_apply_flag_2(t, buf, tmp);
	return (tmp);
}

char		*ft_add_empty(char *tmp, int *tab, char *buffer)
{
	int		n;
	int		i;
	char	tmp2[tab[4] + 1];

	i = 0;
	n = ft_strlen(tmp);
	if (tab[0] == '-')
		while (tab[4] - n)
			tmp[n++] = tab[3];
	else
	{
		ft_bzero(tmp2, tab[4] + 1);
		while ((tmp[0] == '-' || tmp[0] == '+' || tmp[0] == 'x' || tmp[0] == '0'
					|| tmp[0] == 'X' || tmp[0] == ' ') && tab[3] == '0')
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
	return (tmp);
}
