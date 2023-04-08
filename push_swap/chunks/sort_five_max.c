/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:56:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/08 13:22:22 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pusher(t_node** stack_a, t_node** stack_b)
{
	// t_node* tmp;

	t_node_details* min;
	t_node_details* max;
	t_node_details* mid;

	special_nodes(stack_a, &min, &max, &mid);
	if (!min->node->prev
		&& ((*stack_b)->value < min->value || (*stack_b)->value > max->value))
		push(stack_b, stack_a, "pa");
	else if (min->node->prev)
	{
		// find spot
		// while (min_val_node || tmp)
		// {
		// 	if (min_val_node->prev->value < (*stack_b)->value
		// 		&& min_val_node->value >(*stack_b)->value)
		// 	{
		// 	}
		// 	min_pos--;
		// 	min_val_node = min_val_node->next;
		// 	tmp = tmp->next;
		// }
		// if (min_val_node->prev->value > )
		// {
		// 	/* code */
		// }
	}
}

void re_sort(t_node** stack_a)
{
	t_node_details* min;
	t_node_details* max;
	t_node_details* mid;

	special_nodes(stack_a, &min, &max, &mid);
	if (min->pos > mid->pos)
	{
		while (min->pos != 0)
		{
			reverse_rotate(stack_a, "rra");
			special_nodes(stack_a, &min, &max, &mid);
		}
	}
	else if (min->pos <= mid->pos)
	{
		while (min->pos != 0)
		{
			rotate(stack_a, "ra");
			special_nodes(stack_a, &min, &max, &mid);
		}
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
