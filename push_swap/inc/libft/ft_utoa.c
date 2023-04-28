/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:20:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:48:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	char	*ptr;
	int		len;

	len = ft_nbrlen_uns(n);
	ptr = ft_calloc(len + 1, sizeof(char));
	ptr[len] = '\0';
	if (!ptr)
		return (NULL);
	while (len-- && n != 0)
	{
		ptr[len] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
