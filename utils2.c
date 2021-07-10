#include "headers/ft_printf.h"

int	ft_putchar_pf(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_pf(str[i]);
		i++;
	}
	return (i);
}

int	put_width(char c, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		ft_putchar_pf(c);
		i++;
	}
	return (i);
}

int	count_num(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
