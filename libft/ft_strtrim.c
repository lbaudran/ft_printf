/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaudran <lbaudran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:56:16 by lbaudran          #+#    #+#             */
/*   Updated: 2015/12/17 14:15:13 by lbaudran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		n;

	n = 0;
	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	j = ft_strlen(s);
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\0' || s[j] == '\n')
			&& j != i)
		j--;
	str = malloc((j - i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (i != (j + 1))
		str[n++] = s[i++];
	str[n] = '\0';
	return (str);
}
