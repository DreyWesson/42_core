/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:54:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/31 23:53:04 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[j] = s2[i];
		j++;
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}
// int main(void)
// {
// 	printf("%s\n", ft_strjoin("Drey","Oduwole"));
// 	return (0);
// }
