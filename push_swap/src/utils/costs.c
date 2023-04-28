/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:55:29 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/28 06:57:53 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	exit_cost(t_node **stack, int size, int mid_pos)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->list_idx <= mid_pos)
			tmp->exit_cost = tmp->list_idx;
		else
			tmp->exit_cost = tmp->list_idx - size;
		tmp = tmp->next;
	}
}

void	target_cost(t_node **stack_a, t_node **stack_b,
	t_details *details, int size)
{
	char		found;
	t_node		*tmp;
	t_node		*last_node;

	last_node = ft_last_node(*stack_a);
	tmp = *stack_b;
	while (tmp)
	{
		found = 'n';
		head_to_tail(stack_a, tmp, &found, last_node);
		if (found != 'y')
			min_max_handler(tmp, &found, size, details);
		if (found != 'y')
			waterfall(tmp, &found, details, size);
		if (found != 'y')
			spring(tmp, &found, details, size);
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

t_node	*highest_priority(t_node **stack_b, t_node **stack_a)
{
	int		nbr;
	t_node	*tmp;
	t_node	*highest;

	nbr = 2147483647;
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->priority < nbr)
			highest_helper(&highest, tmp, &nbr);
		else if ((tmp->priority == nbr && tmp->value > (*stack_a)->value
				&& highest->value < tmp->value))
			highest_helper(&highest, tmp, &nbr);
		else if (tmp->priority == nbr && tmp->value < (*stack_a)->value
			&& highest->value > tmp->value)
			highest_helper(&highest, tmp, &nbr);
		tmp = tmp->next;
	}
	return (highest);
}
