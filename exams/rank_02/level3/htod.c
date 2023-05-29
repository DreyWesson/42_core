#include <unistd.h>
#include <stdio.h>

void	print_hex(int nbr)
{
	char	x;

	x = 0;
	if (nbr >=16)
		print_hex(nbr / 16);
	x = nbr % 16;
	if (x < 10)
		x += 48;
	else
		x += 55;
	write(1, &x, 1);
}

long	ft_pow(int d, int e)
{
	long res;

	res = 1;
	if (e == 0)
		return (1);
	e--;
	while (e-- >= 0)
		res *= d;
	return res;
}

void htod(char *str)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int res = 0;

	while (str[++i]);
	i--;
	while (str[j])
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			tmp = (str[i] - 55);
		else if (str[i] >= '0' && str[i] <= '9')
			tmp = (str[i] - 48);
		res += tmp * (int)ft_pow(16, j);
		i--;
		j++;
	}
	printf("%d\n", res);
}

int main(void)
{
	// print_hex(6711);
	// ft_pow(16, 2);
	htod("2D");
	return (0);
}