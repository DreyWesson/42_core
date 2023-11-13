/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 06:08:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/31 23:50:51 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// *******CAUSING USUAL BUG in GNL 
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*str;

// 	if (!s)
// 		return (0);
// 	if (ft_strlen(s) <= start)
// 		len = 0;
// 	if (ft_strlen(s) - start < len)
// 		len = ft_strlen(s + start);
// 	str = ft_calloc(len + 1, sizeof(char));
// 	if (!str)
// 		return (0);
// 	ft_memmove(str, s + start, len);
// 	return (str);
// }
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str = (char *)ft_calloc(sizeof(*s), 1);
		str[0] = '\0';
		return (str);
	}
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
	{
		return (NULL);
	}
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

// int	main(void)
// {
// 	ft_printf("%s\n", ft_substr("hola", 2, 2));
// 	return (0);
// }
