#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *)(s + n) = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	t;

	t = count * size;
	if (!count || !size)
		t = 1;
	else if (t / count != size)
		return (NULL);
	ptr = malloc(t);
	if (ptr)
		ft_bzero(ptr, t);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char *ptr;
	size_t i;

	ptr = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}