#include <stdio.h>



int	is_power_2(int n)
{
	int number;

	number = 1;
	while (number <= n)
		number *= 2;
	if ((number / 2) == n)
		return (1);
	return (0);
}



int main(void)
{
	printf("%d\n", is_power_2(22));
}