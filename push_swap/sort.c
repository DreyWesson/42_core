/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:42:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/06 10:39:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_max(t_node** head_ref)
{
	int mid_pos;
	int max_pos;
	int min_pos;
	int** ptr;

	if (is_sorted(head_ref))
		return;
	if (lst_size(head_ref) == 2)
		return (swap_nodes(*head_ref, (*head_ref)->next, "sa"));
	ptr = find_min_max(head_ref);

	min_pos = ptr[0][0];
	mid_pos = ptr[1][0];
	max_pos = ptr[2][0];
	if (max_pos < mid_pos)
		rotate(head_ref, "ra");
	else if (max_pos > mid_pos)
		swap_nodes(*head_ref, (*head_ref)->next, "sa");
	else if ((min_pos < mid_pos || min_pos > mid_pos))
		reverse_rotate(head_ref, "rra");
	free(ptr);
	sort_three_max(head_ref);
}


void repeat_push(t_node** x, t_node** y, int num, char* ptr)
{
	int i;

	i = -1;
	while (++i < num)
		push(x, y, ptr);
}
void repeat_rotate(t_node** x, int num, char* ptr)
{
	int i;

	i = -1;
	while (++i < num)
		rotate(x, ptr);
}
void repeat_reverse(t_node** x, int num, char* ptr)
{
	int i;

	i = -1;
	while (++i < num)
		reverse_rotate(x, ptr);
}


void sort_more(t_node** stack_a, t_node** stack_b, int num)
{
	int** ptr;
	int min_val;
	int mid_val;
	int max_val;


	repeat_push(stack_a, stack_b, num - 3, "pb");
	sort_three_max(stack_a);
	ptr = find_min_max(stack_a);
	min_val = ptr[0][1];
	mid_val = ptr[1][1];
	max_val = ptr[2][1];

	while (*stack_b)
	{
		if ((*stack_b)->value > max_val)
		{
			push(stack_b, stack_a, "pa");
			rotate(stack_a, "ra");
		}
		else if ((*stack_b)->value < min_val)
		{
			ft_printf("MIN\n");
			push(stack_b, stack_a, "pa");
		}
		else if ((*stack_b)->value > mid_val && (*stack_b)->value < max_val)
		{
			// while loop to reverse till the value is lesser
			reverse_rotate(stack_a, "rra");
			push(stack_b, stack_a, "pa");
		}
		else if ((*stack_b)->value > min_val && (*stack_b)->value < mid_val)
		{

			push(stack_b, stack_a, "pa");
			swap_nodes(*stack_a, (*stack_a)->next, "sa");
		}
	}
	ptr = find_min_max(stack_a);
	if (is_sorted(stack_a))
		return;
	if (ptr[0][0] > ptr[1][0])
	{
		while (ptr[0][0] != 0)
		{
			reverse_rotate(stack_a, "ra");
			ptr = find_min_max(stack_a);
		}
	}
	else
	{
		while (ptr[0][0] != 0)
		{
			rotate(stack_a, "ra");
			ptr = find_min_max(stack_a);
		}
	}
}
