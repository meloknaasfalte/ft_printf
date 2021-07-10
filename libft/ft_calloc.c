#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	r;

	r = size * nmemb;
	p = malloc(r);
	if (!p)
		return (NULL);
	if (p)
		ft_memset(p, '\0', r);
	return (p);
}
