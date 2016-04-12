#include <stdio.h>

int main()
{
	long double i;
	double		c;

	i = 100.50;
	i += 0.000000001;
	printf("%.10Lf", i);

}

