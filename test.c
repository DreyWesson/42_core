#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int main()
{
	char **str;
	char **ptr;
	int i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * 3);

	ptr = (char **)malloc(sizeof(char *) * 3);

	str[0] = "drey";
	str[1] = "oduwole";
	str[2] = NULL;
	while (str[i])
	{
		ptr[i] = (char *)malloc(sizeof(char) * 8);
		ft_strcpy(ptr[i], str[i]);
		i++;
	}
	i = 0;
	while (ptr[i])
	{
		printf("-> %s\n", ptr[i]);
		i++;
	}


	return (0);
}