#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	len_s;
	size_t	len_sub;

	i = 0;
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	len_sub = len_s - start;
	if (len_sub < len)
		len = len_sub;
	if (start > len_s)
		len = 0;
	res = malloc(sizeof (char) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
