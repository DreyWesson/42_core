/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 09:16:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/21 10:15:18 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_trim_front(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	len;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	len = ft_strlen(s1);
	str = malloc(len - start + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < len)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
// int main(void){
// 	char str[7] = "000912";
// 	char *ptr;

// 	ptr = ft_trim_front(str, "0");
// 	ft_printf("%c\n",ptr[0]);
// 	return (0);
// }
