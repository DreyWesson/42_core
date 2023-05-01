
#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write(1, "2", 1);
			ft_putnbr(147483648);
			return ;
		}
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	if (n < 10)
	{
		n += '0';
		write(1, &n, 1);
	}
}

void fizz_buzz(n)
{
	int	i;

	i = 0;
	while (++i <= n)
	{
		if (!(i % 5) && !(i % 3))
			write(1, "fizzbuzz", 8);
		else if (!(i % 5))
			write(1, "fizz", 4);
		else if (!(i % 3))
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
	}
}

int	main(void)
{
	fizz_buzz(30);
	return (0);
}
