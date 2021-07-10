#include "headers/ft_printf.h"


int ft_putchar_pf(char c)
{
	write (1, &c, 1);
	return (1);
}

int ft_putstr_pf(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar_pf(str[i]);
		i++;
	}
	return (i);
}

