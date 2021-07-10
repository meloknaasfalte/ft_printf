#include <stdio.h>
#include "headers/ft_printf.h"


int main()
{
	int p;
	int p2;


	char *str = NULL;
	char *ser = "nini";

	p = ft_printf("[%p]\n", "NULL");

	p2 = printf("{%p}\n", "NULL");

	if (p == p2)
		printf("GOOD {%i} [%i]\n", p, p2);
	else
		printf("BAD {%i} [%i]\n", p, p2);
	return(0);
}
