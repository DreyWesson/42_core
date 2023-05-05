#include <stdio.h>

int		max(int* tab, int len)
{
	int i = 0;
	int max = - 2147483648;

	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	printf("%d\n", max);
	return (max);
}
int main(void)
{
	int ptr[4] = {12, 12345, 1, 4};
	max(ptr, 4);
	return (0);
}