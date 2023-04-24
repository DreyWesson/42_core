/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:55:29 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 10:10:47 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void exit_cost(t_node** stack)
{
	int mid_pos;
	t_node* tmp;

	mid_pos = mid_node_details(stack)->pos;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->list_idx <= mid_pos)
			tmp->exit_cost = tmp->list_idx;
		else
			tmp->exit_cost = tmp->list_idx - lst_size(stack);
		tmp = tmp->next;
	}
}

void target_cost(t_node** stack_a, t_node** stack_b)
{
	char found;
	t_node* tmp;
	t_details* details;

	tmp = *stack_b;

	details = special_nodes(stack_a);
	while (tmp)
	{
		found = 'n';
		end_to_end(stack_a, tmp, &found);
		if (found != 'y')
			min_max_handler(stack_a, tmp, &found);
		if (found != 'y')
			fwd(stack_a, tmp, &found, details);
		if (found != 'y')
			rwd(stack_a, tmp, &found, details);
		tmp = tmp->next;
	}
}

void optimize(t_node** stack_b)
{
	t_node* tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if ((tmp->exit_cost >= 0 && tmp->target_cost >= 0)
			|| (tmp->exit_cost <= 0 && tmp->target_cost <= 0))
		{
			if (tmp->exit_cost <= tmp->target_cost)
				tmp->optimized = tmp->exit_cost;
			else
				tmp->optimized = tmp->target_cost;
		}
		tmp = tmp->next;
	}
}

void priority(t_node** stack_b)
{
	t_node* tmp;

	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->exit_cost >= 0 && tmp->target_cost >= 0)
		{
			if (tmp->exit_cost >= tmp->target_cost)
				tmp->priority = tmp->exit_cost;
			else
				tmp->priority = tmp->target_cost;
		}
		else if (tmp->exit_cost <= 0 && tmp->target_cost <= 0)
		{
			if (tmp->exit_cost <= tmp->target_cost)
				tmp->priority = tmp->exit_cost;
			else
				tmp->priority = tmp->target_cost;
		}
		else if (tmp->exit_cost < 0 && tmp->target_cost > 0) {

			tmp->priority = (-1 * tmp->exit_cost) + tmp->target_cost;
		}
		else if (tmp->exit_cost > 0 && tmp->target_cost < 0) {

			tmp->priority = (-1 * tmp->target_cost) + tmp->exit_cost;
		}
		else
			printf("Wadda hell\n");
		tmp = tmp->next;
	}
}
