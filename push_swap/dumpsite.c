/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumpsite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:04:17 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 11:07:35 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int fastforward(t_node* min_node, t_node** stack_b,
	char* found, t_node** stack_a)
{
	t_node* tmp;

	tmp = min_node;
	while (tmp->next)
	{
		if (tmp->value < (*stack_b)->value
			&& (*stack_b)->value < tmp->next->value)
		{
			*found = 'y';
			break;
		}
		tmp = tmp->next;
	}
	if (*found != 'y')
		return (0);
	return (target_pos(stack_a, tmp->value));
}

int rewind_node(t_node* min_node, t_node** stack_b,
	char* found, t_node** stack_a)
{
	t_node* tmp;

	tmp = min_node;
	while (tmp->prev)
	{
		if (tmp->prev->value < (*stack_b)->value
			&& (*stack_b)->value < tmp->value)
		{
			*found = 'y';
			break;
		}
		tmp = tmp->prev;
	}
	if (*found != 'y')
		return (0);
	return (target_pos(stack_a, tmp->value) - 1);
}



void pusher(t_node** stack_a, t_node** stack_b)
{
	t_details* details;
	int pos;
	char found;

	found = 'n';
	details = special_nodes(stack_a);
	pos = 0;
	pos += fastforward(details->min->node, stack_b, &found, stack_a);
	if (details->min->node->prev && found != 'y')
		pos += rewind_node(details->min->node, stack_b, &found, stack_a);
	if (found == 'y')
		move_picker(stack_a, pos, details->mid->pos);
	else
	{
		if ((*stack_b)->value > details->max->value)
		{
			if (ft_last_node(*stack_a)->value != details->max->value)
				move_picker(stack_a, target_pos(stack_a, details->max->value), details->mid->pos);
		}
		else if ((*stack_b)->value < details->min->value)
		{
			if ((*stack_a)->value != details->min->value)
				move_picker(stack_a, target_pos(stack_a, details->max->value), details->mid->pos);
		}
	}
	push(stack_b, stack_a, "pa");
}
