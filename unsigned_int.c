#include "headers/ft_printf.h"

char	*ft_convert(char *s, unsigned int n, int len)
{
	s[len--] = '\0';
	while (n >= 10)
	{
		s[len--] = n % 10 + '0';
		n = n / 10;
	}
	s[len--] = n % 10 + '0';
	return (s);
}

int	print_unint(unsigned int n, t_flags *flags)
{
	char			*res;
	int				minus;
	unsigned int	num;
	int				num_len;
	int				char_count;

	minus = 0;
	n = (unsigned int)(4294967295 + 1 + n);
	if (n < 0)
	{
		minus = 1;
		num = -n;
	}
	else
		num = n;
	num_len = count_num(num) + minus;
	res = ((char *) malloc(sizeof (char) *(num_len + 1)));
	if (!res)
		return (0);
	res = ft_convert(res, num, num_len);
	if (minus)
		res[num_len] = '-';
	char_count = print_string(res, flags);
	free(res);
	return (char_count);
}
