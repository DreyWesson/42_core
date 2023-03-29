/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:42:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 23:55:58 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_max(t_node** head_ref)
{
	int mid_pos;
	int max_pos;
	int min_pos;
	int* ptr;

	if (is_sorted(head_ref))
		return;
	if (lst_size(head_ref) == 2)
		return (swap_nodes(*head_ref, (*head_ref)->next, "sa"));
	ptr = find_min_max(head_ref);
	min_pos = ptr[0];
	mid_pos = ptr[1];
	max_pos = ptr[2];

	if (max_pos < mid_pos)
		rotate(head_ref, "ra");
	else if (max_pos > mid_pos)
		swap_nodes(*head_ref, (*head_ref)->next, "sa");
	else if ((min_pos < mid_pos || min_pos > mid_pos))
		reverse_rotate(head_ref, "rra");
	sort_three_max(head_ref);
}
