/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:44:20 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 22:01:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int* check_position(t_node** head_ref, int max, int min)
{
	t_node* tmp;
	int* ptr;
	int size;

	size = 0;
	ptr = (int*)malloc(sizeof(int) * 3);
	tmp = *head_ref;
	while (tmp)
	{
		if (tmp->value == max)
			ptr[2] = size;
		if (tmp->value == min)
			ptr[0] = size;
		size++;
		tmp = tmp->next;
	}
	size = lst_size(head_ref);
	if (size % 2)
		ptr[1] = size / 2;
	else
		ptr[1] = (size / 2) + 1;
	return (ptr);
}

int* find_min_max(t_node** head_ref)
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

