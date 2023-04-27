/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:59:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/27 12:35:48 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_max_handler(t_node *exiting_node, char *found,
	int size, t_details *details)
{
	if ((exiting_node->value < details->min->node->value)
		|| (exiting_node->value > details->max->node->value))
	{
		if (details->min->pos > details->mid->pos)
			exiting_node->target_cost
				= details->min->node->list_idx - size;
		else
			exiting_node->target_cost = details->min->node->list_idx;
		*found = 'y';
	}
}

void	waterfall(t_node *exiting_node,
	char *found, t_details *details, int size)
{
	t_node	*tmp;
	int		mid_pos;

	tmp = details->min->node;
	mid_pos = details->mid->pos;
	*found = 'n';
	while (tmp->next)
	{
		if (tmp->value < exiting_node->value
			&& exiting_node->value < tmp->next->value)
		{
			*found = 'y';
			if (tmp->next->list_idx <= mid_pos)
				exiting_node->target_cost = tmp->next->list_idx;
			else
				exiting_node->target_cost = tmp->list_idx - size + 1;
			break ;
		}
		tmp = tmp->next;
	}
}

void	spring(t_node *exiting_node,
	char *found, t_details *details, int size)
{
	t_node	*tmp;
	int		mid_pos;

	*found = 'n';
	tmp = details->min->node;
	mid_pos = details->mid->pos;
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
			break ;
		}
		tmp = tmp->prev;
	}
}

void	head_to_tail(t_node **stack_a, t_node *exiting_node,
	char *found, t_node *last_node)
{
	if (last_node->value < exiting_node->value
		&& exiting_node->value < (*stack_a)->value)
	{
		exiting_node->target_cost = 0;
		*found = 'y';
	}
}
