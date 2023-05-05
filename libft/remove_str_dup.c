/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_str_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:11:18 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/03 11:12:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *remove_dup(char *s1)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (s1[i])
	{
		j = i + 1;
		k = j;
		while (s1[j])
		{
			if (s1[j] != s1[i])
				s1[k++] = s1[j];
			j++;
		}
		s1[k] = '\0';
		i++;
	}
	return (s1);
}