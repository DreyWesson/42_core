/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:49:02 by ioduwole          #+#    #+#             */
/*   Updated: 2022/05/21 20:24:31 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			j = i;
		}
		i++;
	}
	if ((unsigned char) str[i] == (unsigned char) c)
		return ((char *)(str + i));
	if (j == 0 && (unsigned char) str[0] != (unsigned char) c)
		return (NULL);
	return ((char *)(str + j));
}
