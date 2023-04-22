/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:55:29 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/21 21:48:48 by doduwole         ###   ########.fr       */
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

char fwd(t_node** stack_a, t_node* exiting_node)
{
	t_node* tmp;
	int mid_pos;
	int size;
	char found;

	tmp = min_node_details(stack_a)->node;
	mid_pos = mid_node_details(stack_a)->pos;
	size = lst_size(stack_a);
	found = 'n';
	while (tmp)
	{
		if (tmp->value < exiting_node->value
			&& exiting_node->value < tmp->next->value)
		{
			found = 'y';
			if (tmp->list_idx <= mid_pos)
				exiting_node->target_cost = tmp->list_idx;
			else
				exiting_node->target_cost = tmp->list_idx - size;
			break;
		}
		tmp = tmp->next;
	}
	return (found);
}

int rwd(t_node** stack_a, t_node* exiting_node)
{
	t_node* tmp;
	int mid_pos;
	int size;
	char found;

	found = 'n';
	tmp = min_node_details(stack_a)->node;
	mid_pos = mid_node_details(stack_a)->pos;
	size = lst_size(stack_a);
	while (tmp->prev)
	{
		if (tmp->prev->value < exiting_node->value
			&& exiting_node->value < tmp->value)
		{
			found = 'y';
			if (tmp->list_idx <= mid_pos)
				exiting_node->target_cost = tmp->list_idx;
			else
				exiting_node->target_cost = tmp->list_idx - size;
			break;
		}
		tmp = tmp->prev;
	}
	return (found);
}

void target_cost(t_node** stack_a, t_node** stack_b)
{
	char found;
	// t_node* tmp;
	t_node* exiting_node;
	t_node_details* max;
	t_node_details* min;
	t_node* last_node;

	// tmp = *stack_a;
	exiting_node = *stack_b;
	max = max_node_details(stack_a);
	min = min_node_details(stack_a);
	last_node = ft_last_node(*stack_a);
	while (exiting_node)
	{
		if (max->value < exiting_node->value || min->value < exiting_node->value)
		{
			exiting_node->target_cost = min->node->list_idx;
			return;
		}
		found = fwd(stack_a, exiting_node);
		if (found == 'y')
			return;
		found = rwd(stack_a, exiting_node);
		if (found == 'y')
			return;
		if (exiting_node->value < (*stack_a)->value
			&& exiting_node->value > last_node->value)
			exiting_node->target_cost = 0;
		exiting_node = exiting_node->next;
	}
}
