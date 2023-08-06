/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:11:22 by ioduwole          #+#    #+#             */
/*   Updated: 2022/11/21 15:08:36 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_count(unsigned int nbr)
{
	int	digit;

	digit = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		digit++;
		nbr /= 16;
	}
	return (digit);
}

void	ft_hexi(char *str, unsigned int n, int i, char c)
{
	int	temp;

	str[i] = '\0';
	i--;
	while (i >= 0)
	{
			temp = n % 16;
		if (temp < 10)
		{
			str[i] = temp + 48;
			i--;
		}
		else
		{
			if (c == 'x')
				str[i] = temp + 87;
			else if (c == 'X')
				str[i] = temp + 55;
			i--;
		}
		n = n / 16;
	}
}

char	*ft_puthexi(unsigned int n, char c)
{
	char	*str;
	int		digit;

	digit = num_count(n);
	str = malloc((digit + 1) * sizeof(char));
	ft_hexi(str, n, digit, c);
	return (str);
}
