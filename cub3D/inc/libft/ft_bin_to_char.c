/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:03:37 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:36:48 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	bin_to_char(int **ptr)
{
	static char		c;
	int				byte_idx;
	int				bit_idx;
	int				val;

	byte_idx = 0;
	while (ptr[byte_idx])
	{
		bit_idx = 0;
		while (bit_idx < 8)
		{
			val = ptr[byte_idx][bit_idx];
			if (val == 1)
				c = (c << 1) | 1;
			else if (val == 0)
				c <<= 1;
			bit_idx++;
			ft_printf("%d\n", c);
		}
		byte_idx++;
	}
	return (c);
}
