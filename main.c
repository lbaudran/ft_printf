#include "libftprintf.h"
#include "stdio.h"

int main()
{
	double i = 100.1234567;
	char *test = "1234567890";
	ft_printf("lol%glol\n", i);
	printf("lol%glol\n", i);
	return (0);
}

