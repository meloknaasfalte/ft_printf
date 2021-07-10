#include "headers/ft_printf.h"

int	print_char(char c, t_flags *flags)
{
	if (flags->width <= 1)
		return (ft_putchar_pf(c));
	put_width(' ', flags->width - 1);
	ft_putchar_pf(c);
	return (flags->width);
}

int	print_string(char *str, t_flags *flags)
{
	int	len;

	if (!str)
		return (print_string("(null)", flags));
	len = ft_strlen(str);
	if (len >= flags->width)
		return (ft_putstr_pf(str));
	put_width(' ', flags->width - len);
	ft_putstr_pf(str);
	return (flags->width);
}

int	print_int(int num, t_flags *flags)
{
	char	*str_number;
	int		char_count;

	str_number = ft_itoa(num);
	char_count = print_string(str_number, flags);
	free (str_number);
	return (char_count);
}
