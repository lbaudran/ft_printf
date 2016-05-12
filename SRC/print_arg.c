/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:55:42 by rfernand          #+#    #+#             */
/*   Updated: 2016/05/02 16:25:45 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*print_arg(int *tab, va_list *arg, t_list *elem, const char *fmt)
{
	char	*buffer;
	char	*(*types[17])(va_list *arg, char *buffer, int *tab, t_list *elem);

	ft_putprintf(tab, elem);
	init_pt_tab(types);
	buffer = types[tab[7]](arg, buffer, tab, elem);
	free(elem->line);
	if ((tab[7] != 11 || tab[6] != 3) &&
			tab[7] != 16 && (tab[7] != 12 || tab[6] != 3))
		buffer = ft_apply_flag(tab, buffer, elem);
	else
		ft_apply_flag_unicode(tab, elem);
	elem->line = (char *)malloc((ft_strlen(buffer) + ft_strlen(fmt) + 1) *
			sizeof(char));
	ft_bzero(elem->line, ft_strlen(buffer) + ft_strlen(fmt) + 1);
	ft_strcat(elem->line, buffer);
	free(buffer);
	if (elem->aff_null && tab[4] > 0 && tab[0] == '-')
	{
		ft_memmove(elem->line + 1, elem->line, ft_strlen(elem->line));
		elem->line[0] = '\0';
	}
	ft_putprintf(tab, elem);
	return (elem->line);
}

void		ft_apply_flag_unicode_2(int *tab, int n, t_list *elem)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc((tab[4] - n + 1) * sizeof(char));
	ft_bzero(tmp, tab[4] - n + 1);
	while (tab[4] - n)
	{
		tmp[i++] = tab[3];
		n++;
	}
	elem->index += ft_printf("%s", tmp);
	free(tmp);
}

void		ft_apply_flag_unicode(int *tab, t_list *elem)
{
	int		i;
	int		n;
	int		y;
	char	*tmp;

	y = 0;
	i = 0;
	n = 0;
	if (tab[3] == 0 && tab[7] == 11)
		tab[3] = ' ';
	if (tab[0] == '-')
		while (elem->unicode[i])
			ft_printwchar(elem->unicode[i++], elem);
	y = i;
	i = 0;
	while (elem->unicode[i])
		n += ft_size_octet(elem->unicode[i++]);
	if (n < tab[4])
		ft_apply_flag_unicode_2(tab, n, elem);
	i = 0;
	if (tab[0] != '-')
		while (elem->unicode[y])
			ft_printwchar(elem->unicode[y++], elem);
	elem->unicode[0] = '\0';
	ft_bzero(elem->unicode, y);
}

char		*ft_apply_flag(int *t, char *buf, t_list *elem)
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
	tmp = ft_apply_flag_2(t, buf, tmp, elem);
	return (tmp);
}

char		*ft_add_empty(char *tmp, int *tab, char *buffer, t_list *elem)
{
	int		n;
	int		i;
	char	tmp2[tab[4] + 1];

	i = 0;
	n = ft_strlen(tmp);
	if (tab[0] == '-')
	{
		while (tab[4] - n)
			tmp[n++] = tab[3];
		return (tmp);
	}
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
	return (tmp);
}
