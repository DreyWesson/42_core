/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:08:30 by doduwole          #+#    #+#             */
/*   Updated: 2023/02/02 11:57:20 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	lesser_num(int *n, char *ptr, int *len, int base)
{
	if (*n == 0)
		ptr[0] = '0';
	if (*n < 0)
	{
		ptr[0] = '-';
		if (*n == -2147483648)
		{
			ptr[--(*len)] = '8';
			*n /= base;
		}
		*n = -(*n);
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	len = ft_nbrlen(n);
	ptr = ft_calloc(len + 1, sizeof(char));
	ptr[len] = '\0';
	if (!ptr)
		return (NULL);
	if (n <= 0)
		lesser_num(&n, ptr, &len, 10);
	while (len-- && n != 0)
	{
		ptr[len] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
