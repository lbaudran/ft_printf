/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:22:52 by lbaudran          #+#    #+#             */
/*   Updated: 2015/11/27 19:38:54 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != c && *str)
		str++;
	if (c == '\0' && str == '\0')
		return ((char *)str);
	else if (c == *str)
		return ((char *)str);
	else
		return (NULL);
}
