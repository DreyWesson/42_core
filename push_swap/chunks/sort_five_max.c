/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:56:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:33:30 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_picker(t_node **stack, int target_pos, int mid_pos)
{
	int	size;

	size = lst_size(stack);
	if (target_pos <= mid_pos)
		repeat_rotate(stack, target_pos, "ra");
	else if (target_pos > mid_pos)
		repeat_reverse(stack, size - target_pos, "rra");
}

void	double_opportunity(t_node *highest, int num,
			t_node **stack_a, t_node **stack_b)
{
	if (highest->optimized != 0)
	{
		if (highest->optimized > 0)
		{
			num = highest->optimized;
			repeat_double_rotate(stack_a, stack_b, num);
			highest->exit_cost -= num;
			highest->target_cost -= num;
		}
		else if (highest->optimized < 0)
		{
			num = highest->optimized;
			repeat_double_reverse(stack_a, stack_b, num);
			highest->exit_cost += (num * -1);
			highest->target_cost += (num * -1);
		}
	}
}

void	exit_moves(t_node *highest, t_node **stack_b)
{
	if (highest->exit_cost > 0)
	{
		repeat_rotate(stack_b, highest->exit_cost, "rb");
		highest->exit_cost = 0;
	}
	else if (highest->exit_cost < 0)
	{
		repeat_reverse(stack_b, highest->exit_cost * -1, "rrb");
		highest->exit_cost = 0;
	}
}

void	target_moves(t_node *highest, t_node **stack_a)
{
	if (highest->target_cost > 0)
	{
		repeat_rotate(stack_a, highest->target_cost, "ra");
		highest->target_cost = 0;
	}
	else if (highest->target_cost < 0)
	{
		repeat_reverse(stack_a, highest->target_cost * -1, "rra");
		highest->target_cost = 0;
	}
}

void	sort_more(t_node **stack_a, t_node **stack_b)
{
	t_node	*highest;
	int		num;

	num = 0;
	handle_indexing(stack_a);
	push_unsorted_only(stack_a, stack_b, "pb");
	while (*stack_b)
	{
		reconfigure(stack_a, stack_b);
		highest = highest_priority(stack_b);
		double_opportunity(highest, num, stack_a, stack_b);
		exit_moves(highest, stack_b);
		target_moves(highest, stack_a);
		if (highest->exit_cost == 0 && highest->target_cost == 0)
			push(stack_b, stack_a, "pa");
		if (!is_sorted(stack_a) && !is_cyclic(stack_a))
			break ;
	}
	re_sort(stack_a);
}
