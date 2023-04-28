/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:17:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/29 17:41:02 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	size_t	c1;
	size_t	c2;

	i = 0;
	while (i < n)
	{
		c1 = (*(unsigned char *)(s1 + i));
		c2 = (*(unsigned char *)(s2 + i));
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
// int	main(void)
// {
// 	// int arr1[5] = {9,2,3,4,5};
// 	// int arr2[5] = {1,2,3,4,5};
// 	char arr1[] = "abc";
// 	char arr2[] = "abd";
// 	ft_memcmp(arr1, arr2, 3);
// 	printf("%d\n", ft_memcmp(arr1, arr2, sizeof(int)*5));
// 	return (0);
// }
