/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:11:50 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/16 12:59:03 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = (void *)malloc((ft_strlen(str) + 1));
	if (!str2)
		return (NULL);
	while (*str)
		str2[i++] = *str++;
	str2[i] = '\0';
	return (str2);
}
