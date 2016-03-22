/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:49:54 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/17 15:53:45 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		str[i++] = '\0';
	str[i] = '\0';
	return (str);
}
