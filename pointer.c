#include "headers/ft_printf.h"

char	*itoa_pointer(unsigned long p)
{
	char	*res;
	int		len;

	len = 0;
	len = count_hexnum(p);
	res = ((char *) malloc(sizeof (char) *(len + 1)));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (p != 0)
	{
		if ((p % 16) < 10)
			res[len--] = (p % 16) + 48;
		else
			res[len--] = (p % 16) + 87;
		p /= 16;
	}
	return (res);
}

int	print_pointer(unsigned long p, t_flags *flags)
{
	char	*str;
	int		char_count;
	int		len;

	char_count = 0;
	if (p == 0)
		return (print_string("0x0", flags));
	str = itoa_pointer(p);
	len = ft_strlen(str);
	char_count += put_width(' ', flags->width - 11);
	char_count += ft_putstr_pf("0x1");
	char_count += put_width('0', 8 - len);
	char_count += ft_putstr_pf(str);
	free (str);
	return (char_count);
}
