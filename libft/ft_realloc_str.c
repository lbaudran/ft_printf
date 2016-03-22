#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_realloc_str(char *str, size_t size)
{
	char	*s;

	s = (char *)malloc(ft_strlen(str) + 1);
	ft_bzero(s, (ft_strlen(str) + 1));
	ft_strcpy(s, str);
//	if(str)
//		free(str);
	str = malloc(size + 1);
	ft_bzero(str, size + 1);
	ft_strcpy(str, s);
	free(s);
	return (str);
}
