/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:44:20 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/06 15:08:11 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int** check_position(t_node** head_ref, int max, int min)
{
	t_node* tmp;
	int** ptr;
	int mid;
	int size;

	size = 0;
	ptr = (int**)malloc(sizeof(int*) * 3);
	while (size < 3)
	{
		ptr[size] = (int*)malloc(sizeof(int) * 2);
		size++;
	}
	size = 0;
	tmp = *head_ref;
	mid = lst_size(head_ref) / 2;
	ptr[1][0] = mid;

	while (tmp)
	{
		if (tmp->value == max) {
			ptr[2][0] = size;
			ptr[2][1] = tmp->value;
		}
		if (tmp->value == min) {
			ptr[0][0] = size;
			ptr[0][1] = tmp->value;
		}
		if (size == mid)
			ptr[1][1] = tmp->value;
		size++;
		tmp = tmp->next;
	}
	return (ptr);
}

int** find_min_max(t_node** head_ref)
{
	long min;
	long max;
	t_node* tmp;

	min = 2147483647;
	max = -2147483648;
	tmp = *head_ref;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (check_position(head_ref, max, min));
}

