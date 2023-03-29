/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:42:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 17:22:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_max(t_node** head_ref)
{
	if (is_sorted(head_ref))
		return;

	if (lst_size(head_ref) == 2)
		return swap_nodes(*head_ref, (*head_ref)->next, "sa");


	// if (/* condition */)
	// {
	// 	/* code */
	// }
	// else if ()
	// {
	// 	/* code */
	// }


	// CASE 1: if pos1 > pos2&& pos1 > pos3 // 3 1 2
	// 	-> rotate 1 2 3

	// 	CASE 4: if pos1 > pos2&& pos1 > pos3// 3 2 1
	// 	-> rotate 2 1 3
	// 	CASE 2 -> 1 2 3

	// 	CASE 2: if pos1 > pos2&& pos1 < pos3 // 2 1 3
	// 	-> swap 1 2 3

	// 	CASE 3: if pos1 < pos2&& pos1 > pos3 // 2 3 1
	// 	-> reverse rotate 1 2 3

	// 	CASE 5 : if pos1 < pos2&& pos1 < pos3 1 3 2
	// 	->reverse rotate 2 1 3
	// 	CASE 2 -> 1 2 3
	// 	sort_three(head_ref);
}
