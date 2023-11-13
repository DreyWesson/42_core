/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:08:47 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 15:03:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	helper(int bit_index, int byte_index, int **ptr, char *str)
{
	int	i;

	i = 0;
	while (bit_index >= 0)
	{
		ptr[byte_index][i++] = (str[byte_index] >> bit_index) & 1;
		bit_index--;
	}
}

int	**char_to_bin(char *str)
{
	int	**ptr;
	int	byte_index;
	int	bit_index;

	byte_index = 0;
	while (str[byte_index])
		byte_index++;
	ptr = calloc(byte_index + 1, sizeof(int *));
	if (!ptr)
		return (0);
	byte_index = 0;
	while (str[byte_index])
	{
		ptr[byte_index] = calloc(sizeof(int), 8);
		if (!ptr[byte_index])
			return (0);
		bit_index = 7;
		helper(bit_index, byte_index, ptr, str);
		byte_index++;
	}
	return (ptr);
}
