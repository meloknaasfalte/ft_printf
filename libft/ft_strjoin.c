#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	l;
	size_t	len1;
	size_t	len2;
	char	*r;

	l = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	r = malloc(sizeof(char) *(len1 + len2 + 1));
	if (!r)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[l])
		r[i++] = s2[l++];
	r[i] = '\0';
	return (r);
}
