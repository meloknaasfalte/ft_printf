#include "headers/ft_printf.h"

void ft_init_flags(t_flags *flags)
{
	flags->length = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;

}

int ft_is_type(char type)
{
	return (type == 'i' || type == 'd' || type == 's' || type == 'u' ||
	type == 'x' || type == 'p' || type == '%'|| type == 'c');
}

int	parse_flags(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (ft_is_type(str[i]))
			break;
		if (str[i] == '-')
			flags->minus = 1;
		if (str[i] == '0' && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '.')
			flags->precision = 0;
		if (str[i] == '*' && flags->precision == -1)
			flags->width = va_arg(args, int);
		if (str[i] == '*' && flags->precision != -1)
			flags->precision = va_arg(args, int);
		if (str[i] >= '0' && str[i] <= '9' && flags->precision == -1)
			flags->width  = (str[i] - '0' ) + flags->width * 10;
		if (str[i] >= '0' && str[i] <= '9' && flags->precision != -1)
			flags->precision  = (str[i] - '0' ) + flags->precision * 10;
			i++;
	}
	return (i);
}

int	parse_type(char c, t_flags *flags, va_list args)
{
	int counter;

	if (c == 'd' || c == 'i')
		counter = print_int(va_arg(args, int), flags);
	if (c == 'u')
		counter = print_unint(va_arg(args,unsigned int), flags);
	if (c == 'c')
		counter = print_char(va_arg(args,int), flags);
	if (c == 's')
		counter = print_string(va_arg(args, char *), flags);
	if (c == 'p')
		counter = print_pointer(va_arg(args, unsigned int), flags);
	if (c == 'x')
		counter = print_hex(va_arg(args, unsigned int), flags, 0);
	if (c == 'X')
		counter = print_hex(va_arg(args, unsigned int), flags, 1);
	if (c == '%')
		counter = print_char('%', flags);

	return (counter);
}

int ft_parse_str(const char *str, va_list args)
{
	int 	i;
	t_flags	flags;
	int		char_count;

	i = 0;
	char_count = 0;
	while (str[i])
	{
		if(str[i] != '%')
			char_count += ft_putchar_pf(str[i]);
		else
		{
			ft_init_flags(&flags);
			i = parse_flags(str, ++i, &flags, args);
			char_count += parse_type(str[i], &flags, args);
		}
		i++;
	}
	return(char_count);
}

int ft_printf(const char *str, ...)
{
	va_list	args;
	int 	count;

	va_start(args, str);
	count = ft_parse_str(str, args);
	va_end(args);
	return (count);
}



