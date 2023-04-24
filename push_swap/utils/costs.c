/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:55:29 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 07:39:28 by doduwole         ###   ########.fr       */
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

void min_max_handler(t_node** stack_a, t_node* exiting_node, char* found)
{

	t_details* details;

	details = special_nodes(stack_a);
	if ((exiting_node->value < details->min->node->value)
		|| (exiting_node->value > details->max->node->value))
	{
		if (details->min->pos > details->mid->pos)
			exiting_node->target_cost = details->min->node->list_idx - lst_size(stack_a);
		else
			exiting_node->target_cost = details->min->node->list_idx;
		*found = 'y';
	}
}



void fwd(t_node** stack_a, t_node* exiting_node, char* found, t_details* details)
{
	t_node* tmp;
	int mid_pos;
	int size;

	tmp = details->min->node;
	mid_pos = details->mid->pos;
	size = lst_size(stack_a);
	*found = 'n';
	while (tmp->next)
	{
		if (tmp->value < exiting_node->value
			&& exiting_node->value < tmp->next->value)
		{
			*found = 'y';
			if (tmp->list_idx <= mid_pos)
				exiting_node->target_cost = tmp->next->list_idx;
			else
				exiting_node->target_cost = tmp->list_idx - size;
			break;
		}
		tmp = tmp->next;
	}
}

int rwd(t_node** stack_a, t_node* exiting_node, char* found, t_details* details)
{
	t_node* tmp;
	int mid_pos;
	int size;

	*found = 'n';
	tmp = details->min->node;
	mid_pos = details->mid->pos;
	size = lst_size(stack_a);
	*found = 'n';
	while (tmp->prev)
	{
		if (tmp->prev->value < exiting_node->value
			&& exiting_node->value < tmp->value)
		{
			*found = 'y';
			if (tmp->list_idx <= mid_pos)
				exiting_node->target_cost = tmp->list_idx;
			else
				exiting_node->target_cost = tmp->list_idx - size;
			break;
		}
		tmp = tmp->prev;
	}
	return (target_pos(stack_a, tmp->value) - 1);
}

void end_to_end(t_node** stack_a, t_node* exiting_node, char* found)
{
	t_node* last_node;

	last_node = ft_last_node(*stack_a);
	if (last_node->value < exiting_node->value && exiting_node->value < (*stack_a)->value)
	{
		exiting_node->target_cost = 0;
		*found = 'y';
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
