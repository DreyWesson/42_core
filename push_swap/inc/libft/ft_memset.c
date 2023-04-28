/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:47:49 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/18 15:57:00 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int n, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(s + i) = (unsigned char) n;
		i++;
	}
	return (s);
}
// int	main(void)
// {
// 	// int arr[2] = {1,2};

// 	// ft_memset(arr,28, 8);
// 	ft_memset(((void *)0), 'a', 12);
// 	// for (int i =0; i < 2; i++)
//     // 	printf("%i\n", arr[i]);
// 	return (0);
// }
