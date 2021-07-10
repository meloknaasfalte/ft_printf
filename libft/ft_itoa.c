#include "libft.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_convert(char *s, unsigned int n, int *len)
{
	s[(*len)--] = '\0';
	while (n >= 10)
	{
		s[(*len)--] = (char)(n % 10 + '0');
		n = n / 10;
	}
	s[(*len)--] = (char)(n % 10 + '0');
	return (s);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*res;
	int				len;
	int				minus;

	minus = 0;
	if (n < 0)
	{
		num = -n;
		minus = 1;
	}
	else
		num = n;
	len = ft_count((int) num) + minus;
	res = ((char *) malloc(sizeof (char) *(len + 1)));
	if (!res)
		return (NULL);
	res = ft_convert(res, num, &len);
	if (minus)
		res[len] = '-';
	return (res);
}
