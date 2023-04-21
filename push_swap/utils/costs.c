/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:55:29 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/21 19:10:20 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void exit_cost(t_node** stack)
{
	int mid_pos;
	t_node* tmp;

	mid_pos = mid_node_details(stack)->pos;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->list_idx <= mid_pos)
			tmp->exit_cost = tmp->list_idx;
		else
			tmp->exit_cost = tmp->list_idx - lst_size(stack);
		tmp = tmp->next;
	}
}
