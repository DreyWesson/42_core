/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:52:31 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/07 11:02:53 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

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
int is_prime(int num)
{
	int i = 1;
	static int nbr;

	nbr = 0;

	while (i <= num)
	{
		if ((i % 2 && i != 1) || i == 2)
			nbr += i;
		i++;
	}
	printf("%d\n", nbr);
	return (nbr);
}

int main(int argc, char**argv)
{
	if (argc == 2)
	{
		is_prime(atoi(argv[1]));
	}
}