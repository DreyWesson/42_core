#include <unistd.h>
#include <stdio.h>

char    *ft_strrev(char *str)
{
	int i = 0;
	int j = -1;
	char tmp;

	while (str[++j]);
	j--;
	while (i <= j / 2)
	{
		tmp = str[i];
		str[i] = str[j - i];
		str[j - i] = tmp;
		i++;
	}
	return str;
}
