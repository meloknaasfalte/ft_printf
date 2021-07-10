#include <stdio.h>
#include "headers/ft_printf.h"


int main()
{
	int p;
	int p2;


	char *str = NULL;
	char *ser = "nini";

	p = ft_printf("[%u]\n", 123);

	p2 = printf("{%u}\n", 123);

	if (p == p2)
		printf("GOOD {%i} [%i]\n", p, p2);
	else
		printf("BAD {%i} [%i]\n", p, p2);
	return(0);
}
