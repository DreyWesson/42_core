/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:17:39 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/21 10:39:14 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int* bubble_sort(int* ptr, int size)
{
	int i;
	int j;
	int cache;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (ptr[i] < ptr[j])
			{
				cache = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = cache;
			}
			j++;
		}
		i++;
	}
	return (ptr);
}
