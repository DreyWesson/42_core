/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:32:21 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/07 10:20:14 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
			bit = ((byte >> j) & 1) + '0'; // right shift by j times using >> and check what is the rightmost bit with & operator
			write(1, &bit, 1);
			j++;
		}
		write(1, " ", 1);
		i++;
	}
}

// unsigned char	reverse_bits(unsigned char octet)
// {
// 	int i;
// 	unsigned char bit;
// 	i = 0;
// 	while (i < 8)
// 	{
// 		bit = ((octet >> i) & 1) + '0';
// 		write(1, &bit, 1);
// 		i++;
// 	}
// 	return (bit);
// }
unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

int main(void)
{
	// int a = 38;
	char a = 'z';
	// reverse_bit(sizeof(int), &a);
	// write(1, "\n", 1);
	printf("%c\n",reverse_bits(a));

	return 0;
}