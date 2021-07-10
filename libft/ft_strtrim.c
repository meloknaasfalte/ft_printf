#include "libft.h"

static	int	ft_is_char_set(int c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	j;
	size_t	start;
	char	*res;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_is_char_set(s1[start], set))
		start++;
	len = ft_strlen(s1);
	while (len > start && ft_is_char_set(s1[len - 1], set))
		len--;
	res = ((char *) malloc(sizeof (char) * (len - start + 1)));
	if (!res)
		return (NULL);
	j = 0;
	while (start < len)
	{
		res[j] = s1[start];
		j++;
		start++;
	}
	res[j] = '\0';
	return (res);
}
