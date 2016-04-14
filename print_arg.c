/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:55:42 by rfernand          #+#    #+#             */
/*   Updated: 2016/04/14 17:06:32 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*print_arg(int *tab, va_list *arg, char *str, const char *format)
{
	char *buffer;
	char *buf;
	int n;
	char	*(*types[15])(va_list *arg, char *buffer, int *tab);

//	printf("%s\n\n", str);
	n = ft_strlen(str);
	buffer = NULL;
	buf = (char *)malloc((n + 1) * sizeof(char));
	ft_strcpy(buf, str);
	if (!tab[7])
		return (NULL);
	init_pt_tab(types);
	buffer = types[tab[7]](arg, buffer, tab);
	free (str);
	str = (char *) malloc((n + ft_strlen(buffer) + ft_strlen(format) + 1) *
			sizeof (char));
	ft_bzero(str, n + ft_strlen(buffer) + ft_strlen(format) + 1);
	ft_strcpy(str, buf);
	free(buf);
	ft_strcat(str, buffer);
//	printf("test%s\ntest\n\n", str);
	free(buffer);
	return (str);
}
