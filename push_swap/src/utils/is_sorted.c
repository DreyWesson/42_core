/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:43:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/05 20:15:44 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	is_sorted(t_node **head_ref)
{
	t_node	*tmp;

	if (!head_ref)
		return (0);
	tmp = *head_ref;
	while (tmp)
	{
		if (tmp->prev && tmp->prev->value > tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	validate_forward(t_node *min_node, t_node **stack_a)
{
	t_node	*tmp;

	tmp = min_node;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			break ;
		tmp = tmp->next;
	}
	if (ft_last_node(*stack_a)->value == tmp->value)
		return (1);
	return (0);
}

int	validate_backward(t_node *min_node, t_node **stack_a)
{
	t_node	*tmp;

	tmp = min_node->prev;
	while (tmp->prev)
	{
		if (tmp->value < tmp->prev->value)
			break ;
		tmp = tmp->prev;
	}
	if ((*stack_a)->value == tmp->value)
		return (1);
	return (0);
}

int	is_cyclic(t_node **stack_a)
{
	t_node_details	*min;

	min = min_node_details(stack_a);
	if (min->node->next && min->node->prev)
	{
		if ((*stack_a)->value < ft_last_node(*stack_a)->value
			|| (*stack_a)->value == min->value)
			return (free(min), 0);
	}
	if (min->node->next && !validate_forward(min->node, stack_a))
		return (free(min), 0);
	if (min->node->prev && !validate_backward(min->node, stack_a))
		return (free(min), 0);
	free(min);
	return (1);
}
