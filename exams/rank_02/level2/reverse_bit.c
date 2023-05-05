/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:32:21 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/05 17:15:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

void reverse_bit(unsigned int size, void* value){
	char *data;
	long long i, j;
	char byte;
	char bit;

	data = (char *)value; // char pointer helps us save as much bytes regardless of the data type
	i = 0;
	while (i < (long long) size)
	{
		j = 0;
		byte = data[i];
		while (j < 8)
		{
			bit = (byte >> j) & 1; // right shift by j times using >> and check what is the rightmost bit with & operator
			ft_putnbr(bit);
			j++;
		}
		write(1, " ", 1);
		i++;
	}
}

int main(void)
{
	int a = 38;
	reverse_bit(sizeof(int), &a);
	write(1, "\n", 1);
	return 0;
}