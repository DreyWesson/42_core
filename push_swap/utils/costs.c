/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:55:29 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/26 23:14:35 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_cost(t_node **stack)
{
	int		mid_pos;
	t_node	*tmp;
	int size;

	mid_pos = mid_node_details(stack)->pos;
	tmp = *stack;
	size = lst_size(stack);
	while (tmp)
	{
		if (tmp->list_idx <= mid_pos)
			tmp->exit_cost = tmp->list_idx;
		else
			tmp->exit_cost = tmp->list_idx - size;
		tmp = tmp->next;
	}
}

void	target_cost(t_node **stack_a, t_node **stack_b)
{
	char		found;
	t_node		*tmp;
	t_details	*details;

	tmp = *stack_b;
	details = special_nodes(stack_a);
	while (tmp)
	{
		found = 'n';
		head_to_tail(stack_a, tmp, &found);
		if (found != 'y')
			min_max_handler(stack_a, tmp, &found);
		if (found != 'y')
			waterfall(stack_a, tmp, &found, details);
		if (found != 'y')
			spring(stack_a, tmp, &found, details);
		tmp = tmp->next;
	}
	free(details);
}

void	optimize(t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->exit_cost > 0 && tmp->target_cost > 0)
		{
			if (tmp->exit_cost <= tmp->target_cost)
				tmp->optimized = tmp->exit_cost;
			else
				tmp->optimized = tmp->target_cost;
		}
		else if (tmp->exit_cost < 0 && tmp->target_cost < 0)
		{
			if (tmp->exit_cost <= tmp->target_cost)
				tmp->optimized = tmp->target_cost;
			else
				tmp->optimized = tmp->exit_cost;
		}
		else 
			tmp->optimized = 0;
		tmp = tmp->next;
	}
}

void	priority(t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->exit_cost > 0 && tmp->target_cost > 0)
			both_positive(tmp);
		else if (tmp->exit_cost < 0 && tmp->target_cost < 0)
			both_negative(tmp);
		else if (tmp->exit_cost < 0 && tmp->target_cost > 0)
			tmp->priority = (-1 * tmp->exit_cost) + tmp->target_cost;
		else if (tmp->exit_cost > 0 && tmp->target_cost < 0)
			tmp->priority = tmp->exit_cost + (-1 * tmp->target_cost);
		else if (tmp->exit_cost == 0)
			exit_zero(tmp);
		else if (tmp->target_cost == 0)
			target_zero(tmp);
		tmp = tmp->next;
	}
}

t_node	*highest_priority(t_node **stack_b)
{
	int		nbr;
	t_node	*tmp;
	t_node	*highest;

	nbr = 2147483647;
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->priority < nbr)
		{
			highest = tmp;
			nbr = tmp->priority;
		}
		tmp = tmp->next;
	}
	return (highest);
}
