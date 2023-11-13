/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:10:43 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/31 23:57:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s || !f)
		return (NULL);
	ptr = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
// char	f(unsigned int i, char c)
// {
// 	printf("%c\t%i\n", c, i);
// 	return (c);
// }

// int	main(void)
// {
// 	ft_strmapi("Drey", f);
// 	return (0);
// }
