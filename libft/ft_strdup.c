#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	l;
	char	*ds ;

	l = 0;
	i = ft_strlen(s);
	ds = malloc(i + 1);
	if (!ds)
		return (NULL);
	while (s[l])
	{
		ds[l] = s[l];
		l++;
	}
	ds[l] = '\0';
	return (ds);
}
