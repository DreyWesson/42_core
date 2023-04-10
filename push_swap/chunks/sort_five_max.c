/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:56:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/10 08:37:48 by doduwole         ###   ########.fr       */
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
			*found = 'y';
			break;
		}
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int rest_node(t_node** head_ref, int num)
{
	t_node* tmp;
	int size;

	if (!head_ref)
		return (0);
	size = 0;
	tmp = *head_ref;
	while (tmp && tmp->value != num)
	{
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
	while (tmp->prev)
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

void move_picker(t_node** stack, int target_pos, int mid_pos)
{
	int size;

	size = lst_size(stack);
	if (target_pos <= mid_pos)
		repeat_rotate(stack, target_pos, "ra");
	else if (target_pos > mid_pos)
		repeat_reverse(stack, size - target_pos, "rra");
}

void pusher(t_node** stack_a, t_node** stack_b)
{
	t_node_details* min;
	t_node_details* mid;
	t_node_details* max;
	int pos;
	char found;

	found = 'n';
	special_nodes(stack_a, &min, &mid, &max);
	// ft_print_nodes(stack_a);
	pos = 1;
	pos += fastforward(min->node, stack_b, &found);
	if (min->node->prev && found != 'y')
		pos += rewind_node(min->node, stack_b, &found);
	else if (min->node->prev && found == 'y')
		pos += rest_node(stack_a, min->value);
	if (found == 'y')
		move_picker(stack_a, pos, mid->pos);
	else
	{
		//******REFACTOR******: to else if
		if ((*stack_b)->value > max->value || (*stack_b)->value < min->value)
			move_picker(stack_a, min->pos, mid->pos);
	}
	push(stack_b, stack_a, "pa");
	// ft_print_nodes(stack_a);
}

void re_sort(t_node** stack_a)
{
	t_node_details* min;
	t_node_details* mid;

	min = min_node_details(stack_a);
	mid = mid_node_details(stack_a);
	move_picker(stack_a, min->pos, mid->pos);
}

void sort_more(t_node** stack_a, t_node** stack_b, int threshold_num)
{
	push_unsorted_only(stack_a, stack_b, lst_size(stack_a), "pb");
	if (lst_size(stack_a) == threshold_num)
		sort_three_max(stack_a, 'y');
	while (*stack_b)
		pusher(stack_a, stack_b);
	if (is_sorted(stack_a))
		return;
	re_sort(stack_a);
}
