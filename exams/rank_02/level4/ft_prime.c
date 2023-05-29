// Assignment name  : fprime
// Expected files   : fprime.c
// Allowed functions: printf, atoi
// --------------------------------------------------------------------------------

// Write a program that takes a positive int and displays its prime factors on the
// standard output, followed by a newline.

// Factors must be displayed in ascending order and separated by '*', so that
// the expression in the output gives the right result.

// If the number of parameters is not 1, simply display a newline.

// The input, when there is one, will be valid.

// Examples:

// $> ./fprime 225225 | cat -e
// 3*3*5*5*7*11*13$
// $> ./fprime 8333325 | cat -e
// 3*3*5*5*7*11*13*37$
// $> ./fprime 9539 | cat -e
// 9539$
// $> ./fprime 804577 | cat -e
// 804577$
// $> ./fprime 42 | cat -e
// 2*3*7$
// $> ./fprime 1 | cat -e
// 1$
// $> ./fprime | cat -e
// $
// $> ./fprime 42 21 | cat -e
// $
#include <unistd.h>

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

char handle_sign(char *str, int *itr)
{
	int i;
	char is_neg;

	i = 0;
	is_neg = 'n';
	if (str[i] && str[i] == '-')
		is_neg = 'y';
	if (str[i] == '+' || str[i] == '-')
		i++;
	*itr = i;
	return (is_neg);
}

int	atoi(char *str)
{
	signed int nbr;
	int i;
	char is_neg;

	i = 0;
	nbr = 0;
	trim_space(str, &i);
	is_neg = handle_sign(str, &i);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (is_neg == 'y')
		return (-nbr);
	return (nbr);
}

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

int main(int argc, char **argv)
{
	int nbr;
	int i;
	int tmp;
	int star;

	i = 2;
	star = 0;
	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		tmp = nbr;
		while (i < tmp)
		{
			if (nbr % i == 0)
			{
				nbr /= i;
				if (star > 0)
					write(1, "*", 1);
				star++;
				ft_putnbr(i);
			}
			else
				i++;
		}
	}
	return (0);
}