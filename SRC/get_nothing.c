/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nothing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 19:01:45 by lbaudran          #+#    #+#             */
/*   Updated: 2016/05/02 16:37:28 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_nothing(va_list *arg, char *buffer, int *tab, t_list *elem)
{
	buffer = (char *)malloc(2 * sizeof(char));
	buffer[0] = tab[8];
	buffer[1] = '\0';
	return (buffer);
}

char	*ft_apply_flag_2(int *t, char *buf, char *tmp, t_list *elem)
{
	char	*(*diez[11])(char *tmp, char *buffer, int *tab);

	init_diez_tab(diez);
	if (t[1] && ((t[7] >= 6 && t[7] <= 10) || t[7] == 1) && buf[0] != '-')
		tmp[0] = t[1];
	if (t[2] && ((t[7] >= 4 && t[7] <= 10) || t[7] == 2 || t[7] == 14))
		buf = diez[t[7]](tmp, buf, t);
	ft_strcat(tmp, buf);
	if (t[4] > (int)ft_strlen(buf))
		tmp = ft_add_empty(tmp, t, buf, elem);
	free(buf);
	return (tmp);
}
