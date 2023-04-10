/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:56:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/10 20:42:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int rest_node(t_node* min_node)
{
	t_node* tmp;
	int size;

	size = 0;
	tmp = min_node;
	while (tmp->prev)
	{
		size++;
		tmp = tmp->prev;
	}
	return (size);
}

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
	if (*found != 'y')
		return (0);
	// if you found it from what position are you counting from
	// if min pos is zero return size
	if (min_node_details(&min_node)->pos != 0)
	{
		size += (size + rest_node(min_node));
	}

	return (size);

}

int rewind_node(t_node* min_node, t_node** stack_b, char* found)
{
	t_node* tmp;
	int size;
	int half_total;

	size = 0;
	half_total = 0;
	tmp = min_node;
	while (tmp->prev)
	{
		if (*found != 'y')
			size++;
		if (tmp->prev->value < (*stack_b)->value
			&& (*stack_b)->value < tmp->value)
		{
			*found = 'y';
		}
		half_total++;
		tmp = tmp->prev;
	}
	if (*found != 'y')
		size = 0;
	return (half_total - size);
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
	pos = 1;
	pos += fastforward(min->node, stack_b, &found);
	if (min->node->prev && found != 'y')
	{
		pos += rewind_node(min->node, stack_b, &found);
	}
	if (found == 'y')
	{
		move_picker(stack_a, pos, mid->pos);
		// conditions if found
		// calculate position
	}
	else
	{
		// conditions if not found in list
		// its lower than minimum
		// its higher than maximum
		// or it should be between head and tail
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
	// BUGGY 
	// 6 1 5 3 4 
	// 4 67 3 27 23
	// 984 167 3 87 23
	// 167 984 3 87 23
	// push_unsorted_only(stack_a, stack_b, lst_size(stack_a), "pb");
	// if (lst_size(stack_a) == threshold_num)
	// 	sort_three_max(stack_a, 'y');
	repeat_push(stack_a, stack_b, threshold_num, "pb");
	sort_three_max(stack_a, 'n');
	while (*stack_b)
		pusher(stack_a, stack_b);
	if (is_sorted(stack_a))
		return;
	re_sort(stack_a);
}
