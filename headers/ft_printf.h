#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int			type;
	int			width;
	int			minus;
	int			precision;
	int			zero;
	int			star;
	int			length;

}	t_flags;

int		ft_printf(const char *str, ...);
int		ft_parse_str(const char *str, va_list args);
int		ft_putchar_pf(char c);
int		print_char(char c, t_flags *flags);
int		ft_putstr_pf(char *str);
int		print_int(int num, t_flags *flags);
int		print_unint(unsigned int num, t_flags *flags);
int		print_string(char *str, t_flags *flags);
int		print_hex(unsigned int n, t_flags *flags, int is_upper);
int		print_pointer(unsigned long p, t_flags *flags);
int		put_width(char c, int width);
int		count_hexnum(unsigned int numb);
int		count_num(unsigned int n);
int		parse_type(char c, t_flags *flags, va_list args);

#endif
