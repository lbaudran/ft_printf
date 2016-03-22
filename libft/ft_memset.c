/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:59:35 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/16 10:55:19 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memset(void *str, int c, size_t len)
{
	char	*str2;

	str2 = str;
	while (len--)
		*str2++ = c;
	return (str);
}
