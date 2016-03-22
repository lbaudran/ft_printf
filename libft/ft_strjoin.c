/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:45:21 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/02 19:08:10 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = (void *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
