/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:42:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 20:26:13 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_max(t_node** head_ref)
{
	// int node_one;
	// int node_two;
	// int node_three;
	int* ptr;
	int i;

	i = 0;
	if (is_sorted(head_ref))
		return;
	if (lst_size(head_ref) == 2)
		return (swap_nodes(*head_ref, (*head_ref)->next, "sa"));
	// node_one = (*head_ref)->value;
	// node_two = (*head_ref)->next->value;
	// node_three = (*head_ref)->next->next->value;

	// {min, mid, max}

	// if max is below mid leave it // ✅ 1 2 3
	// if max is above mid -> rotate // ✅ 3 2 1 // // ✅ 3 1 2
	// if min is below mid && min is below max // ✅ 2 3 1 -> rotate // ✅ 2 1 3
	// if min is below mid && min is above max // ✅ 2 1 3 -> swap
	// if min is above all && unsorted // ✅ 1 3 2 -> swap 3 1 2 -> rotate 1 2 3

	// if (node_one > node_two && node_one > node_three)
	// 	rotate(head_ref, "ra");
	// else if (node_one > node_two && node_one < node_three)
	// 	swap_nodes(*head_ref, (*head_ref)->next, "sa");
	// else if (node_one < node_two && node_one > node_three)
	// 	reverse_rotate(head_ref, "rra");
	// else if (node_one < node_two && node_one < node_three)
	// 	reverse_rotate(head_ref, "rra");
	// sort_three_max(head_ref);
	ptr = find_min_max(head_ref);
	while (i < 2)
	{
		ft_printf("%d\n", ptr[i]);
		i++;
	}
}





