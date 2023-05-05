/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:42:38 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/02 18:14:29 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// write while loop to parse initial garbages
// check if its negative
// check the sign
// run a while loop to save the numbers in 10s
// put the sign
// and return num
#include <stdio.h>
#include <unistd.h>

int	atoi(char *str)
{
	signed int nbr;
	int i;
	char is_neg;

	i = 0;
	nbr = 0;
	is_neg = 'n';
	while (str[i] && (str[i] == ' ' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\f'))
		i++;
	if (str[i] && str[i] == '-')
		is_neg = 'y';
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (is_neg == 'y')
		return (-nbr);
	return (nbr);
}

void	print_num(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			write(1, "2", 1);
			write(1, "147483648", 9);
		}
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		print_num(nbr / 10);
		nbr %= 10;
	}
	if (nbr < 10)
	{
		nbr += '0';
		write(1, &nbr, 1);
	}
}

int	main(int argc, char **argv)
{
	int		res;
	char	arg;

	res = 0;
	arg = *argv[2];
	if (argc == 4)
	{
		if (arg == '+')
			res = atoi(argv[1]) + atoi(argv[3]);
		else if (arg == '-')
			res = atoi(argv[1]) - atoi(argv[3]);
		else if (arg == '/')
			res = atoi(argv[1]) / atoi(argv[3]);
		else if (arg == '*')
			res = atoi(argv[1]) * atoi(argv[3]);
		else if (arg == '%')
			res = atoi(argv[1]) % atoi(argv[3]);
		print_num(res);
	}
	write(1, "\n", 1);

	return (0);
}
