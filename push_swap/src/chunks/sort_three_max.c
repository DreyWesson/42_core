/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:51:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/05 19:57:25 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	mover(t_node **head_ref, int mid_val, int prev_val, int next_val)
{
	if (mid_val > prev_val && mid_val > next_val)
	{
		if (prev_val > next_val)
			reverse_rotate(head_ref, "rra", 1);
		else if (prev_val < next_val)
			swap_nodes(*head_ref, (*head_ref)->next, "sa", 1);
	}
	else if (mid_val < prev_val && mid_val < next_val)
	{
		if (prev_val > next_val)
			rotate(head_ref, "ra", 1);
		else
			swap_nodes(*head_ref, (*head_ref)->next, "sa", 1);
	}
	else
		swap_nodes(*head_ref, (*head_ref)->next, "sa", 1);
}

void	sort_three_max(t_node **head_ref, char check_cyclic)
{
	int				prev_val;
	t_node			*mid_node;
	int				next_val;
	t_node_details	*mid;

	if (is_sorted(head_ref) || (check_cyclic == 'y' && is_cyclic(head_ref)))
		return ;
	if (lst_size(head_ref) == 2)
		return (swap_nodes(*head_ref, (*head_ref)->next, "sa", 1));
	mid = mid_node_details(head_ref);
	mid_node = mid->node;
	prev_val = mid_node->prev->value;
	next_val = mid_node->next->value;
	mover(head_ref, mid_node->value, prev_val, next_val);
	sort_three_max(head_ref, check_cyclic);
	free(mid);
}
