#include "libftprintf.h"
#include "stdio.h"

int main()
{
	double i = -100.12314534;
	char *test = "1234567890";
	ft_printf("%g\n", i);
	ft_printf("%G\n", i);
	printf("%g\n", i);
	printf("%G\n", i);
	return (0);
}

