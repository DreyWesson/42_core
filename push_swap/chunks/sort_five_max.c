/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:56:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/07 15:25:16 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sort_five_handler(t_node** stack_a, t_node** stack_b, int** ptr, int rr_counter)
{
	if ((*stack_b)->value > ptr[2][1])
	{
		push(stack_b, stack_a, "pa");
		// rotate(stack_a, "ra");
	}
	else if ((*stack_b)->value < ptr[0][1])
		push(stack_b, stack_a, "pa");
	else if ((*stack_b)->value > ptr[1][1] && (*stack_b)->value < ptr[2][1])
	{
		while ((*stack_b)->value > (*stack_a)->value)
		{
			reverse_rotate(stack_a, "rra");
			rr_counter++;
		}
		push(stack_b, stack_a, "pa");
		repeat_reverse(stack_a, rr_counter, "rra");
	}
	else if ((*stack_b)->value > ptr[0][1] && (*stack_b)->value < ptr[1][1])
	{
		while ((*stack_b)->value > (*stack_a)->value)
			rotate(stack_a, "ra");
		push(stack_b, stack_a, "pa");
	}
}
void re_sort(t_node** stack_a)
{
	int** ptr;

	ptr = find_min_max(stack_a);
	if (ptr[0][0] > ptr[1][0])
	{
		while (ptr[0][0] != 0)
		{
			reverse_rotate(stack_a, "rra");
			ptr = find_min_max(stack_a);
		}
	}
	else if (ptr[0][0] <= ptr[1][0])
	{
		while (ptr[0][0] != 0)
		{
			rotate(stack_a, "ra");
			ptr = find_min_max(stack_a);
		}
	}
}

void sort_more(t_node** stack_a, t_node** stack_b, int num)
{
	int** ptr;

	repeat_push(stack_a, stack_b, num - 3, "pb");
	sort_three_max(stack_a);
	ptr = find_min_max(stack_a);
	while (*stack_b)
		sort_five_handler(stack_a, stack_b, ptr, 0);
	if (is_sorted(stack_a))
		return;
	re_sort(stack_a);
}
