/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:56:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/09 13:14:12 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int fastforward(t_node* min_node, t_node** stack_b, char* found)
{
	t_node* tmp;
	int size;

	size = 0;
	tmp = min_node;
	while (tmp->next)
	{
		if (tmp->value < (*stack_b)->value
			&& (*stack_b)->value < tmp->next->value)
		{
			// printf("-> %d %d %d\n", tmp->value, (*stack_b)->value, tmp->next->value);
			*found = 'y';
			break;
		}
		size++;
		tmp = tmp->next;
	}
	return (size);
}
int rewind_node(t_node* min_node, t_node** stack_b, char* found)
{
	t_node* tmp;
	int size;

	size = 0;
	tmp = min_node;
	while (tmp->next)
	{
		if (tmp->prev->value < (*stack_b)->value
			&& (*stack_b)->value < tmp->value)
		{
			*found = 'y';
			break;
		}
		size++;
		tmp = tmp->prev;
	}
	return (size);
}

void pusher(t_node** stack_a, t_node** stack_b)
{
	t_node_details* min;
	t_node_details* mid;
	int pos;
	char found;
	int size;

	found = 'n';
	min = min_node_details(stack_a);
	mid = mid_node_details(stack_a);
	pos = 1;
	pos += fastforward(min->node, stack_b, &found);
	size = lst_size(stack_a);

	if (min->node->prev && found != 'y')
	{
		pos += rewind_node(min->node, stack_b, &found);
	}
	// printf("pos: %d mid_pos: %d\n", pos, mid->pos);
	printf("found: %c", found);
	if (pos <= mid->pos && found == 'y')
	{
		// printf("1st half\n");
		repeat_rotate(stack_a, pos, "ra");
	}
	else if (pos > mid->pos && found == 'y')
	{
		repeat_reverse(stack_a, size - pos, "rra");
	}
	push(stack_b, stack_a, "pa");
	ft_print_nodes(stack_a);
}

void re_sort(t_node** stack_a)
{
	t_node_details* min;
	t_node_details* mid;
	int size;

	min = min_node_details(stack_a);
	mid = mid_node_details(stack_a);
	size = lst_size(stack_a);
	if (min->pos <= mid->pos)
	{
		repeat_rotate(stack_a, min->pos, "ra");
	}
	else
	{
		repeat_reverse(stack_a, size - min->pos, "rra");
	}

}

void sort_more(t_node** stack_a, t_node** stack_b, int threshold_num)
{
	repeat_push(stack_a, stack_b, threshold_num, "pb");
	sort_three_max(stack_a);
	while (*stack_b)
		pusher(stack_a, stack_b);
	if (is_sorted(stack_a))
		return;
	re_sort(stack_a);
}
