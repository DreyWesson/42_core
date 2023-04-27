/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:59:26 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/27 08:51:59 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	min_max_handler(t_node **stack_a, t_node *exiting_node, char *found)
{
	t_details	*details;

	details = special_nodes(stack_a);
	if ((exiting_node->value < details->min->node->value)
		|| (exiting_node->value > details->max->node->value))
	{
		if (details->min->pos > details->mid->pos)
			exiting_node->target_cost
				= details->min->node->list_idx - lst_size(stack_a);
		else
			exiting_node->target_cost = details->min->node->list_idx;
		*found = 'y';
	}
	free(details);
}

void	waterfall(t_node **stack_a, t_node *exiting_node,
	char *found, t_details *details)
{
	t_node	*tmp;
	int		mid_pos;
	int		size;

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
			if (tmp->next->list_idx <= mid_pos)
			{
				exiting_node->target_cost = tmp->next->list_idx;
				// printf("----->%d / %d\n", tmp->list_idx, mid_pos);
			}
			else
			{
				exiting_node->target_cost = tmp->list_idx - size + 1;
			// printf("======>%d\n", tmp->list_idx - size + 1);
			}
			break ;
		}
		tmp = tmp->next;
	}
}

int	spring(t_node **stack_a, t_node *exiting_node,
	char *found, t_details *details)
{
	t_node	*tmp;
	int		mid_pos;
	int		size;

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
			{
				exiting_node->target_cost = tmp->list_idx;
			// printf("----->%d\n", tmp->list_idx);

			}
			else
			{
				exiting_node->target_cost = tmp->list_idx - size;
			// printf("======>%d\n", tmp->list_idx - lst_size(stack_a));

			}
			break ;
		}
		tmp = tmp->prev;
	}
	return (target_pos(stack_a, tmp->value) - 1);
}

void	head_to_tail(t_node **stack_a, t_node *exiting_node, char *found)
{
	t_node	*last_node;

	last_node = ft_last_node(*stack_a);
	if (last_node->value < exiting_node->value
		&& exiting_node->value < (*stack_a)->value)
	{
		exiting_node->target_cost = 0;
		*found = 'y';
	}
}

int	target_pos(t_node **stack_a, int target_value)
{
	t_node	*tmp;
	int		size;

	size = 0;
	tmp = *stack_a;
	while (tmp->next)
	{
		size++;
		if (target_value == tmp->value)
			break ;
		tmp = tmp->next;
	}
	return (size);
}
