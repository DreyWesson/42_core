
#include "x.h"

void trim_space(char *str, int *itr)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\f'))
		i++;
	*itr = i;
}
