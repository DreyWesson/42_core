/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:56:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 06:26:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int target_pos(t_node** stack_a, int target_value)
{
	t_node* tmp;
	int size;

	size = 0;
	tmp = *stack_a;
	while (tmp->next)
	{
		size++;
		if (target_value == tmp->value)
			break;
		tmp = tmp->next;
	}
	return (size);
}

int fastforward(t_node* min_node, t_node** stack_b,
	char* found, t_node** stack_a)
{
	t_node* tmp;

	tmp = min_node;
	while (tmp->next)
	{
		if (tmp->value < (*stack_b)->value
			&& (*stack_b)->value < tmp->next->value)
		{
			*found = 'y';
			break;
		}
		tmp = tmp->next;
	}
	if (*found != 'y')
		return (0);
	return (target_pos(stack_a, tmp->value));
}

int rewind_node(t_node* min_node, t_node** stack_b,
	char* found, t_node** stack_a)
{
	t_node* tmp;

	tmp = min_node;
	while (tmp->prev)
	{
		if (tmp->prev->value < (*stack_b)->value
			&& (*stack_b)->value < tmp->value)
		{
			*found = 'y';
			break;
		}
		tmp = tmp->prev;
	}
	if (*found != 'y')
		return (0);
	return (target_pos(stack_a, tmp->value) - 1);
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
	t_details* details;
	int pos;
	char found;

	found = 'n';
	details = special_nodes(stack_a);
	pos = 0;
	pos += fastforward(details->min->node, stack_b, &found, stack_a);
	if (details->min->node->prev && found != 'y')
		pos += rewind_node(details->min->node, stack_b, &found, stack_a);
	if (found == 'y')
		move_picker(stack_a, pos, details->mid->pos);
	else
	{
		if ((*stack_b)->value > details->max->value)
		{
			if (ft_last_node(*stack_a)->value != details->max->value)
				move_picker(stack_a, target_pos(stack_a, details->max->value), details->mid->pos);
		}
		else if ((*stack_b)->value < details->min->value)
		{
			if ((*stack_a)->value != details->min->value)
				move_picker(stack_a, target_pos(stack_a, details->max->value), details->mid->pos);
		}
	}
	push(stack_b, stack_a, "pa");
}

void re_sort(t_node** stack_a)
{
	t_node_details* min;
	t_node_details* mid;

	min = min_node_details(stack_a);
	mid = mid_node_details(stack_a);
	move_picker(stack_a, min->pos, mid->pos);
}

void re_calibrator(t_node** head_ref)
{
	t_node* tmp;
	int i;

	if (!head_ref)
		return;
	i = 0;
	tmp = *head_ref;
	while (tmp)
	{
		tmp->list_idx = i;
		tmp = tmp->next;
		i++;
	}
}

void sort_more(t_node** stack_a, t_node** stack_b)
{
	handle_indexing(stack_a);
	// ft_print_nodes(stack_a, 'v');
	// ✅ check num of values in position
		// ✅ if more than three then dont push those
		// ✅ else push all until 3
	// ✅ calc exit cost of each from stack_b
	// 🔴 calc target cost of each
	// 🔴 check total cost of each by comparing the exit and target cost
	// 🔴 check opportunity to perform double ops if eit and target share same sign
	// 🔴 after every push check if list is sorted cyclically or default sorted

	push_unsorted_only(stack_a, stack_b, "pb");
	// ft_print_nodes(stack_a, ' ');
	// ft_print_nodes(stack_b, ' ');
	// re-evaluate list_idx
	re_calibrator(stack_b);
	re_calibrator(stack_a);
	exit_cost(stack_b);
	target_cost(stack_a, stack_b);

	// ft_print_nodes(stack_a, 'v');
	// ft_print_nodes(stack_b, 'v');

	if (lst_size(stack_a) == 3 && (!is_sorted(stack_a) && !is_cyclic(stack_a)))
		sort_three_max(stack_a, 'y');
	while (*stack_b && (is_cyclic(stack_a) || is_sorted(stack_a)))
		pusher(stack_a, stack_b);
	if (is_sorted(stack_a))
		return;
	re_sort(stack_a);
}

// printf("pos: %d, min_pos: %d\n", pos, min->pos);
// printf("==fwd==>size: %d, target: %d\n", target_pos(stack_a, tmp->value), tmp->value);
// printf("==rwd==>size: %d, target: %d\n", target_pos(stack_a, tmp->value), tmp->value);
// printf("=======> a-top: %d, b-top: %d, max_val: %d, min_val: %d tail: %d, target_pos: %d\n", (*stack_a)->value, (*stack_b)->value, max->value, min->value, ft_last_node(*stack_a)->value, target_pos(stack_a, min->value) - 1);