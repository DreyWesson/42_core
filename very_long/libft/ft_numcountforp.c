/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numcountforp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:47:48 by ioduwole          #+#    #+#             */
/*   Updated: 2022/11/21 15:09:14 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numb_count(unsigned long nbr)
{
	int	digit;

	digit = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 16;
		digit++;
	}
	return (digit);
}
