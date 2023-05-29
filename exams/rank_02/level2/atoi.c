/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:14:47 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/09 09:59:53 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "x.h"

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

int main(int c, char **argv)
{
	(void) c;
	printf("%d\n",atoi(argv[1]));
	return (0);
}
