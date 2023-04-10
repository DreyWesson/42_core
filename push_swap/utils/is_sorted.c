/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:43:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/10 07:11:17 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_sorted(t_node** head_ref)
{
	t_node* tmp;

	if (!head_ref)
		return (0);
	tmp = *head_ref;
	while (tmp)
	{
		if (tmp->prev && tmp->prev->value > tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}


t_node* validate_forward(t_node* min_node, int* size)
{
	t_node* tmp;
	t_node* tmp2;

	tmp = min_node;
	while (tmp)
	{
		if (tmp->next && tmp->value > tmp->next->value)
			break;
		*size += 1;
		tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tmp2);
}


t_node* validate_backward(t_node_details* min_node, int* size)
{
	t_node* tmp;
	t_node* tmp2;

	if (min_node->pos == 0)
		return (NULL);
	tmp = min_node->node->prev;
	while (tmp)
	{
		if (tmp->prev && tmp->prev->value > tmp->value)
			break;
		*size += 1;
		tmp2 = tmp;
		tmp = tmp->prev;
	}
	return (tmp2);
}

int is_cyclic(t_node** stack_a)
{
	static int size;
	t_node_details* min;
	t_node* head;
	t_node* tail;

	min = min_node_details(stack_a);
	size = 0;
	head = validate_forward(min->node, &size);
	tail = validate_backward(min, &size);
	if (size == (lst_size(stack_a)))
	{
		if (min->pos != 0 && head->value > tail->value)
			return (0);
		return (1);
	}
	return (0);
}

