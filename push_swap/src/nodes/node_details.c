/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_details.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:44:20 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/08 12:18:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_node_details	*max_node_details(t_node	**head_ref)
{
	long			max;
	int				pos;
	t_node			*tmp;
	t_node_details	*node_details;

	max = -2147483648;
	tmp = *head_ref;
	pos = 0;
	node_details = (t_node_details *)malloc(sizeof(t_node_details));
	while (tmp)
	{
		if (max < tmp->value)
		{
			node_details->node = tmp;
			node_details->value = tmp->value;
			node_details->pos = pos;
			max = tmp->value;
		}
		pos++;
		tmp = tmp->next;
	}
	return (node_details);
}

t_node_details	*min_node_details(t_node **head_ref)
{
	long			min;
	int				pos;
	t_node			*tmp;
	t_node_details	*node_details;

	min = 2147483647;
	tmp = *head_ref;
	pos = 0;
	node_details = (t_node_details *)malloc(sizeof(t_node_details));
	while (tmp)
	{
		if (min > tmp->value)
		{
			node_details->node = tmp;
			node_details->value = tmp->value;
			node_details->pos = pos;
			min = tmp->value;
		}
		pos++;
		tmp = tmp->next;
	}
	return (node_details);
}

t_node_details	*mid_node_details(t_node **head_ref)
{
	t_node			*tmp;
	t_node_details	*node_details;
	int				size;

	size = 0;
	node_details = (t_node_details *)malloc(sizeof(t_node_details));
	tmp = *head_ref;
	node_details->pos = lst_size(head_ref) / 2;
	while (tmp)
	{
		if (size == node_details->pos)
		{
			node_details->node = tmp;
			node_details->value = tmp->value;
		}
		size++;
		tmp = tmp->next;
	}
	return (node_details);
}

t_details	*special_nodes(t_node **stack_a)
{
	t_details	*all;

	all = (t_details *)malloc(sizeof(t_details));
	all->min = min_node_details(stack_a);
	all->mid = mid_node_details(stack_a);
	all->max = max_node_details(stack_a);
	return (all);
}
