/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 07:32:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/18 15:56:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	j = 0;
	k = ft_strlen(src);
	i = ft_strlen(dest);
	if (size == 0)
		return (k);
	if (size <= i)
		return (size + k);
	while (src[j] != '\0')
	{
		if ((size - 1) == (j + i))
			break ;
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + k);
}
// int	main(void)
// {
// 	char	*s;
//     char	target[128] = "target buffer#";
// 	s = "hello duplicates";
//     printf("Hello World: \"%s\"\n", target);
//     ft_strlcat(target, s, 128);
//     printf("New target: \"%s\"\n", target);
//     return (0);
// }
