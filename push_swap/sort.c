/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:42:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 00:06:26 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three()
{
	// CASE 0: if pos // 1 2 3
		// return

	// CASE 1: if pos1 > pos2 && pos1 > pos3 // 3 1 2
		// -> rotate 1 2 3

	// CASE 4: if pos1 > pos2 && pos1 > pos3// 3 2 1
		// -> rotate 2 1 3
		// CASE 2 -> 1 2 3

	// CASE 2: if pos1 > pos2 && pos1 < pos3 // 2 1 3
		// -> swap 1 2 3

	// CASE 3: if pos1 < pos2 && pos1 > pos3 // 2 3 1
		// -> reverse rotate 1 2 3

	// CASE 5: if pos1 < pos2 && pos1 < pos3 1 3 2
		// -> reverse rotate 2 1 3
		// CASE 2 -> 1 2 3
}
