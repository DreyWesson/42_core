/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:51:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/28 06:55:42 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	mover(t_node **head_ref, int mid_val, int prev_val, int next_val)
{
	if (mid_val > prev_val && mid_val > next_val)
	{
		if (prev_val > next_val)
			reverse_rotate(head_ref, "rra");
		else if (prev_val < next_val)
			swap_nodes(*head_ref, (*head_ref)->next, "sa");
	}
	else if (mid_val < prev_val && mid_val < next_val)
	{
		if (prev_val > next_val)
			rotate(head_ref, "ra");
		else
			swap_nodes(*head_ref, (*head_ref)->next, "sa");
	}
	else
		swap_nodes(*head_ref, (*head_ref)->next, "sa");
}

void	sort_three_max(t_node **head_ref, char check_cyclic)
{
	int		prev_val;
	t_node	*mid_node;
	int		next_val;

	if (is_sorted(head_ref) || (check_cyclic == 'y' && is_cyclic(head_ref)))
		return ;
	if (lst_size(head_ref) == 2)
		return (swap_nodes(*head_ref, (*head_ref)->next, "sa"));
	mid_node = mid_node_details(head_ref)->node;
	prev_val = mid_node->prev->value;
	next_val = mid_node->next->value;
	mover(head_ref, mid_node->value, prev_val, next_val);
	sort_three_max(head_ref, check_cyclic);
}
