/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 11:27:22 by doduwole          #+#    #+#             */
/*   Updated: 2023/01/29 17:56:07 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(char const	*s, char c)
{
	int	count;
	int	i;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const	*s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	arr = (char **)ft_calloc(sizeof(char *), (word_counter(s, c) + 1));
	if (!arr || !s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start != i)
		{
			arr[j] = ft_substr(s, start, i - start);
			j++;
		}
	}
	return (arr);
}
// int	main(void)
// {
// 	char	**ptr;
// 	int		i;

// 	i = 0;
// 	ptr = ft_split("mississippi", 'i');
// 	while (ptr[i] != NULL)
// 	{
// 		printf("%s\n", *(ptr + i));
// 		i++;
// 	}
// 	return (0);
// }
