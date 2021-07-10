#include "libft.h"

char	*ft_strchr (const char *str, int ch)
{
	size_t	i;
	char	c;

	i = 0;
	c = (char)ch;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char *)(str + i));
	return (NULL);
}
