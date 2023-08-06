/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:26:23 by ioduwole          #+#    #+#             */
/*   Updated: 2022/05/21 20:23:10 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char) str[i] == (unsigned char) c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if (str[i] == (unsigned char) c)
		return ((char *)(str + i));
	return (NULL);
}
