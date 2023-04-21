/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:29:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/21 18:41:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int* populate_array(t_node** stack_a)
{
	int* ptr;
	t_node* tmp;
	int i;

	i = 0;
	tmp = *stack_a;
	ptr = (int*)ft_calloc(sizeof(int), lst_size(stack_a));
	while (tmp)
	{
		ptr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (ptr);
}

void handle_indexing(t_node** stack_a)
{
	int* ptr;
	t_node* tmp;
	int i;

	i = 0;
	tmp = *stack_a;
	ptr = populate_array(stack_a);
	bubble_sort(ptr, lst_size(stack_a));
	tmp = *stack_a;
	while (tmp)
	{
		i = 0;
		while (i < lst_size(stack_a))
		{
			if (tmp->value == ptr[i])
				tmp->order_idx = i + 1;
			i++;
		}
		tmp = tmp->next;
	}
	free(ptr);
}
