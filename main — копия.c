#include <stdio.h>
#include "headers/ft_printf.h"


int main()
{
	int p;
	int p2;


	char *str = NULL;
	char *ser = "dsf";

	p = ft_printf("[%1s]\n", "0");

	p2 = printf("{%1s}\n", "0");
	if (p == p2)
		printf("GOOD {%i} [%i]\n", p, p2);
	else
		printf("BAD {%i} [%i]\n", p, p2);
	return(0);
}
