#include "libftprintf.h"
#include "stdio.h"

int main()
{
	char *test = "1234567890";
	printf("%15.-1s", test );
	return (0);
}

