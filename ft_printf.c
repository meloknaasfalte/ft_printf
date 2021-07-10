#include "headers/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = ft_parse_str(str, args);
	va_end(args);
	return (count);
}
