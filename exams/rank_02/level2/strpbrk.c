/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strpbrk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:44:12 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/02 18:46:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *strpbrk(const char *s, const char *charset)
{
	int i = 0;
	int j = 0;

	while (s[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == s[i])
			{
				return s[i];
			}
			j++;
		}
		i++;
	}
	return (NULL);
}