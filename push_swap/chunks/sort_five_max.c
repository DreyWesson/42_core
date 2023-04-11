/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:56:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/11 11:53:39 by doduwole         ###   ########.fr       */
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
	printf("->size: %d\n", size);
	return (size);
}

int fastforward(t_node* min_node, t_node** stack_b, char* found, t_node** stack_a)
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
	printf("==fwd==>size: %d, target: %d\n", target_pos(stack_a, tmp->value), tmp->value);
	ft_print_nodes(stack_a);
	return (target_pos(stack_a, tmp->value));
}

int rewind_node(t_node* min_node, t_node** stack_b, char* found, t_node** stack_a)
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
	printf("==rwd==>size: %d, target: %d\n", target_pos(stack_a, tmp->value), tmp->value);
	ft_print_nodes(stack_a);
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
	t_node_details* min;
	t_node_details* mid;
	t_node_details* max;
	int pos;
	char found;

	found = 'n';
	special_nodes(stack_a, &min, &mid, &max);
	pos = 0;
	pos += fastforward(min->node, stack_b, &found, stack_a);
	ft_print_nodes(stack_a);
	printf("pos: %d, min_pos: %d\n", pos, min->pos);
	if (min->node->prev && found != 'y')
	{
		pos += rewind_node(min->node, stack_b, &found, stack_a);
	}
	// if 0: check if the value is lesser than min or greater than max
	// can it fit between head and tail
	// if (pos == 0)
	// {
	// 	if ((*stack_b)->value < min->value || (*stack_b)->value > max->value)
	// 	{
	// 	}
	// 	printf("last_node val: %d\n", ft_last_node(stack_a)->value);
	// 	if (((*stack_a)->value < (*stack_b)->value) && ((*stack_b)->value > ft_last_node(stack_a)->value))
	// 	{
	// 		push(stack_a, stack_b, "pa");
	// 	}

	// }

	if (found == 'y')
	{
		move_picker(stack_a, pos, mid->pos);
		push(stack_b, stack_a, "pa");
	}
	else
	{
		// conditions if not found in list
		// its lower than minimum
		// its higher than maximum
		// or it should be between head and tail
			//******REFACTOR******: to else if

		if ((*stack_b)->value > max->value || (*stack_b)->value < min->value)
		{
			// ft_print_nodes(stack_a);
			move_picker(stack_a, target_pos(stack_a, min->value) - 1, mid->pos);
			// printf("Problem\n");
			push(stack_b, stack_a, "pa");

		}
		else if (((*stack_a)->value > (*stack_b)->value) && ((*stack_b)->value > ft_last_node(*stack_a)->value))
		{
			// printf("######## a-top: %d, b-top: %d, max_val: %d, min_val: %d tail: %d\n", (*stack_a)->value, (*stack_b)->value, max->value, min->value, ft_last_node(*stack_a)->value);
			// push(stack_a, stack_b, "pa");
			push(stack_b, stack_a, "pa");

		}
		// else
		// 	move_picker(stack_a, min->pos, mid->pos);

	}
	// push(stack_b, stack_a, "pa");
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
