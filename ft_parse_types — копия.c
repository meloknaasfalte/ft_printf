#include "headers/ft_printf.h"

int print_int(int num, t_flags *flags)
{
	char *str_number;

	str_number = ft_itoa(num);
	return (print_string(str_number, flags));
}

static int count_num(unsigned int n)
{
	int count;

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

static char	*ft_convert(char *s, unsigned int n, int len)
{
	s[len--] = '\0';
	while (n >= 10)
	{
		s[len--] = (char)(n % 10 + '0');
		n = n / 10;
	}
	s[len--] = (char)n % 10 + '0';
	return (s);
}

int print_unint(unsigned int n, t_flags *flags)
{
	char *res;
	int minus;
	unsigned int num;
	int num_len;

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
	return (print_string(res, flags));
}

int put_width(char c, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		ft_putchar_pf(c);
		i++;
	}
	return (i);
}

int	print_string(char *str, t_flags *flags)
{
	int len;
	if (!str)
		return (print_string("(null)", flags));

	len = ft_strlen(str);
	if (len >= flags->width)
		return (ft_putstr_pf(str));
	put_width(' ', flags->width - len);
	ft_putstr_pf(str);
	return (flags->width);
}

int print_char(char c, t_flags *flags)
{
	if (flags->width <= 1)
		return (ft_putchar_pf(c));
	put_width(' ', flags->width - 1);
	ft_putchar_pf(c);
	return (flags->width);
}

char *hex_convert(unsigned long n, int len, int is_upper)
{
	char *res;

	res = ((char*) malloc(sizeof (char) * (len + 1)));
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

int count_hexnum(unsigned int numb)
{
	int len;

	len = 0;
	while (numb != 0)
	{
		numb /= 16;
		len++;
	}
	return (len);
}

int print_hex(unsigned int n, t_flags *flags, int is_upper)
{
	unsigned int numb;
	char *res;

	if (n == 0)
		return (print_char('0', flags));
	numb = n;
	numb = (unsigned int)(numb + 4294967295 + 1);
	res = hex_convert(numb, count_hexnum(numb), is_upper);
	return (print_string(res, flags));
}

char *itoa_pointer(unsigned long p)
{
	char *res;
	int	len;

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

int print_pointer(unsigned long p, t_flags *flags)
{
	char *str;
	int char_count;
	int len;
	char_count = 0;
	if (p == 0)
		return (print_string("0x0", flags));
	str = itoa_pointer(p);
	len = ft_strlen(str);
	char_count += put_width(' ', flags->width - 11);
	char_count += ft_putstr_pf("0x1");
	char_count += put_width('0', 8 - len);
	char_count += ft_putstr_pf(str);
	printf("%i", char_count);
	return (char_count);
}