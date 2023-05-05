/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:37:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/05 16:32:00 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	To print bits we have take into consideration that
//	8 bits equal to 1 byte
// 	and therefore to loop through the bits of each byte
//  since char is the smallest representable byte 
// 	we are going to store the first byte of our int in it
//  char byte_idx = (char *)&int_variable[itr];
//	why char pointer? we had to use char pointer 
//	because char being one byte cant accommodate the 4 bytes of an int
//	and using pointer gives us access to the needed memory
// 	Now that we have our int stored in byte_idx then loop over each bit of the byte
// 	using shift and AND bitwise operator
// 	(byte_idx & 1) gives us the right most bit
// 	while byte_idx >>= 1 shifts the bits by one for every iteration

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

void print_bit(unsigned int size, void* value){
	char *data;
	long long i, j;
	char byte;
	char bit;

	data = (char *)value; // char pointer helps us save as much bytes regardless of the data type
	i = 0;
	while (i < (long long) size)
	{
		j = 7;
		byte = data[i];
		while (j >= 0)
		{
			bit = (byte >> j) & 1; // right shift by j times using >> and check what is the rightmost bit with & operator
			ft_putnbr(bit);
			j--;
		}
		write(1, " ", 1);
		i++;
	}
}

int main(void)
{
	int a = 38;
	print_bit(sizeof(int), &a);
	write(1, "\n", 1);
	return 0;
}
