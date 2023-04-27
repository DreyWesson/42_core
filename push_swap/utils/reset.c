/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:16:37 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/27 14:34:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	re_sort(t_node **stack_a)
{
	t_node_details	*min;
	t_node_details	*mid;

	min = min_node_details(stack_a);
	mid = mid_node_details(stack_a);
	move_picker(stack_a, min->pos, mid->pos);
	free(min);
	free(mid);
}

void	re_calibrator(t_node **head_ref)
{
	t_node	*tmp;
	int		i;

	if (!head_ref)
		return ;
	i = 0;
	tmp = *head_ref;
	while (tmp)
	{
		tmp->list_idx = i;
		tmp = tmp->next;
		i++;
	}
}

void	reconfigure(t_node **stack_a, t_node **stack_b)
{
	int			size;
	int			size2;
	t_details	*details;
	int			mid_pos;

	re_calibrator(stack_b);
	re_calibrator(stack_a);
	size = lst_size(stack_a);
	size2 = lst_size(stack_b);
	mid_pos = mid_node_details(stack_b)->pos;
	details = special_nodes(stack_a);
	exit_cost(stack_b, size2, mid_pos);
	target_cost(stack_a, stack_b, details, size);
	optimize(stack_b);
	priority(stack_b);
	// free(details);
}
