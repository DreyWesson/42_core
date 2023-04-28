/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:13:10 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/18 15:57:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(s + i)) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	char src[] = "Copy that";
// 	char c = 'p';
// 	// int src[5] = {1, 2, 3, 4, 5};
// 	// int c = 3;
// 	printf("%p\n", ft_memchr(src, c, sizeof(int) * 5));
// 	return (0);
// }
