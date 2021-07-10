#include "libft.h"

static int	ft_count_str(const char *s, char c)
{
	int	i;
	int	l;
	int	find;

	i = 0;
	l = 0;
	find = 1;
	while (s[i])
	{
		if (s[i] == c && find != 1)
			find = 1;
		else if (s[i] != c && find == 1)
		{
			find = 0;
			l++;
		}
		i++;
	}
	return (l);
}

static	int	ft_char_count(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*ft_free_array(void **res, int i_word)
{
	int	i;

	i = 0;
	while (i < i_word)
	{
		free (res[i]);
		i++;
	}
	free (res);
	return (NULL);
}

static const char	*ft_sep_circle(const char *str, char c)
{
	while (*str == (const char) c)
		str++;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i_word;
	int		len;
	int		char_len;
	int		chr;

	len = ft_count_str(s, c);
	res = ((char **) malloc(sizeof (char *) * (len + 1)));
	if (!res)
		return (NULL);
	i_word = 0;
	while (*s && i_word < len)
	{
		chr = 0;
		s = ft_sep_circle(s, c);
		char_len = ft_char_count(s, c);
		res[i_word] = ((char *) malloc (sizeof(char) * (char_len + 1)));
		if (!res[i_word])
			return (ft_free_array((void **)res, i_word));
		while (chr < char_len)
			res[i_word][chr++] = *(s++);
		res[i_word++][chr] = '\0';
	}
	res[i_word] = NULL;
	return (res);
}
