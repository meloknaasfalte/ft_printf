#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	len_b;
	size_t	len_l;

	len_b = 0;
	if (*lit == '\0')
		return ((char *) big);
	if (!big)
		len_b = big[0];
	len_l = ft_strlen(lit);
	while (len_b + len_l <= len && big[len_b])
	{
		if (big[len_b] == *lit)
		{
			if (!(ft_strncmp(big + len_b, lit, len_l)))
				return ((char *)(big + len_b));
		}
		len_b ++;
	}
	return (NULL);
}
