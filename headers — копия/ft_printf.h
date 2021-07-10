#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>


typedef struct flags
{
	int	type;
	int width;
	int minus;
	int precision;
	int zero;
	int star;
	int length;


} t_flags;
int	ft_printf(const char *str, ...);
int ft_putchar_pf(char c);
int print_char(char c, t_flags *flags);
int ft_putstr_pf(char *str);
int print_int(int num, t_flags *flags);
int print_unint(unsigned int num, t_flags *flags);
int	print_string(char *str, t_flags *flags);
int print_hex(unsigned int n, t_flags *flags, int is_upper);
int print_pointer(unsigned long p, t_flags *flags);




#endif
