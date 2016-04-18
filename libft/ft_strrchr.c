/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:33:56 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/08 12:14:19 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*n;

	n = 0;
	while (*str)
	{
		if (*str == c)
			n = (char *)str;
		str++;
	}
	if (*str == '\0' && c == '\0')
		n = (char *)str;
	return (n);
}
