/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:56:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/05 19:37:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	move_picker(t_node **stack, int target_pos, int mid_pos)
{
	int	size;

	size = lst_size(stack);
	if (target_pos <= mid_pos)
		repeat_rotate(stack, target_pos, "ra", 1);
	else if (target_pos > mid_pos)
		repeat_reverse(stack, size - target_pos, "rra", 1);
}

void	double_opportunity(t_node *highest,
			t_node **stack_a, t_node **stack_b)
{
	if (highest->optimized != 0)
	{
		if (highest->optimized > 0)
			helper(highest, stack_a, stack_b, 'r');
		else if (highest->optimized < 0)
			helper(highest, stack_a, stack_b, '\0');
	}
}

void	exit_moves(t_node *highest, t_node **stack_b)
{
	if (highest->exit_cost > 0)
		repeat_rotate(stack_b, highest->exit_cost, "rb", 1);
	else if (highest->exit_cost < 0)
		repeat_reverse(stack_b, highest->exit_cost * -1, "rrb", 1);
	highest->exit_cost = 0;
}

void	target_moves(t_node *highest, t_node **stack_a)
{
	if (highest->target_cost > 0)
		repeat_rotate(stack_a, highest->target_cost, "ra", 1);
	else if (highest->target_cost < 0)
		repeat_reverse(stack_a, highest->target_cost * -1, "rra", 1);
	highest->target_cost = 0;
}

void	sort_more(t_node **stack_a, t_node **stack_b)
{
	t_node		*highest;
	t_stacks	*stacks;

	handle_indexing(stack_a);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	repeat_push(stacks, lst_size(stack_a) - 3, "pb", 1);
	if (!is_sorted(stack_a) && !is_cyclic(stack_a))
		sort_three_max(stack_a, 'y');
	while (*stack_b)
	{
		reconfigure(stack_a, stack_b);
		highest = highest_priority(stack_b, stack_a);
		double_opportunity(highest, stack_a, stack_b);
		exit_moves(highest, stack_b);
		target_moves(highest, stack_a);
		push(stack_b, stack_a, "pa", 1);
		if (!is_sorted(stack_a) && !is_cyclic(stack_a))
			break ;
	}
	re_sort(stack_a);
	free_both(stacks->stack_a, stacks->stack_b);
	free(stacks);
}
