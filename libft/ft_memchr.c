#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*src;
	size_t			i;

	i = 0;
	ch = (unsigned char)c;
	src = (unsigned char *)s;
	while (i < n)
	{
		if (src[i] == ch)
			return (src + i);
		i++;
	}
	return (NULL);
}
