#include "libft.h"

size_t	ft_strlcat (char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;
	size_t	d;

	i = 0;
	s = ft_strlen(src);
	d = ft_strlen(dst);
	if (d >= size)
		return (s + size);
	i = d;
	while (*src && (i + 1) < size)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (s + d);
}
