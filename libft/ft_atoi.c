#include "libft.h"

int	ft_atoi(const char *n)
{
	int	i;
	int	res;
	int	m;

	i = 0;
	res = 0;
	m = 1;
	while (n[i] == '\n' || n[i] == '\t' || n[i] == '\r' || n[i] == '\v'
		|| n[i] == '\f' || n[i] == ' ')
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			m = -1;
		i++;
	}
	while (ft_isdigit(n[i]))
	{
		res = res * 10 + (n[i++] - '0');
	}
	return (res * m);
}
