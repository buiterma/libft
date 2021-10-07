#include "libft.h"
#include <string.h>

static t_size	ft_wcount(char const *s, char c)
{
	t_size	wcount;
	t_size	i;

	wcount = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
			wcount++;
		while (s[i] != c && s[i + 1])
			i++;
	}
	return (wcount);
}

static t_size	ft_strlen(char const *s, char c)
{
	t_size	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, t_size n)
{
	t_size	i;

	i = -1;
	while (++i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	t_size	wcount;
	t_size	lcount;
	t_size	i;
	t_size	j;

	i = -1;
	j = 0;
	wcount = ft_wcount(s, c);
	out = (char **)calloc(wcount + 1, sizeof(char *));
	if (!s || !wcount || !out)
		return (NULL);
	while (++i < wcount)
	{
		while (s[j] == c)
			j++;
		lcount = ft_strlen(&s[j], c);
		out[i] = (char *)malloc(lcount * sizeof (char) + 1);
		if (out[i])
			j += ft_strlcpy(out[i], &s[j], lcount);
		else
			return (NULL);
	}
	return (out);
}

int main(int argc, char const *argv[])
{
	char	string[] = "This is a string that needs to be split";
	char **new;

	int i;
	i = 0;
	new = ft_split(string, ' ');
	while (new[i])
	{
		printf("%s\n", new[i]);
		i++;
	}
	return 0;
}
