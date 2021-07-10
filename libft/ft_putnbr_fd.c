#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	i = n;
	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		i = n * -1;
	}
	if (i <= 9)
		ft_putchar_fd (i + '0', fd);
	if (i > 9)
	{
		ft_putnbr_fd (i / 10, fd);
		ft_putchar_fd (i % 10 + '0', fd);
	}
}
