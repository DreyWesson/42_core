#include <stdio.h>
#include <stdlib.h>

int stln(char *src)
{
	int i = -1;
	while (src[++i]);
	return (i);
}

int	main(void)
{
	printf("%d\n", stln("hello wjh"));
	return (0);
}
