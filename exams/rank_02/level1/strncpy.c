#include <stdio.h>
#include <stdlib.h>

char	*stpcpy(char *dst, const char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

int	main(void)
{
	char *dst;
	dst = malloc(sizeof(char) * 10);
	printf("%s\n", stpcpy(dst, "hello wjh"));
	free(dst);
	return (0);
}