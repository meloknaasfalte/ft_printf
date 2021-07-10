#include "headers/ft_printf.h"

char	*hex_convert(unsigned long n, int len, int is_upper)
{
	char	*res;

	res = ((char *) malloc(sizeof (char) * (len + 1)));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (n != 0)
	{
		if ((n % 16) < 10)
			res[len--] = (n % 16) + 48;
		else
			res[len--] = (n % 16) + 55;
		if (!is_upper)
			res[len + 1] = ft_tolower(res[len + 1]);
		n /= 16;
	}
	return (res);
}

int	print_hex(unsigned int n, t_flags *flags, int is_upper)
{
	unsigned int	numb;
	char			*res;
	int				char_count;

	if (n == 0)
		return (print_char('0', flags));
	numb = n;
	numb = (unsigned int)(numb + 4294967295 + 1);
	res = hex_convert(numb, count_hexnum(numb), is_upper);
	char_count = print_string(res, flags);
	free(res);
	return (char_count);
}

int	count_hexnum(unsigned int numb)
{
	int	len;

	len = 0;
	while (numb != 0)
	{
		numb /= 16;
		len++;
	}
	return (len);
}
