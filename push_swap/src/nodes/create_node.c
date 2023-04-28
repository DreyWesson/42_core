/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:38:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/28 06:56:22 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_node	*create_node(int value, int i)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->value = value;
	head->list_idx = i;
	head->target_cost = 0;
	head->priority = 0;
	head->optimized = 0;
	head->exit_cost = 0;
	head->order_idx = 0;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}
