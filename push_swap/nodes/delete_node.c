/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:37:07 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 13:37:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node* del_node(t_node** prev_node, t_node* target_node)
{
	if (!*prev_node || !target_node)
		return (NULL);
	if (*prev_node == target_node)
		*prev_node = target_node->next;
	if (target_node->next != NULL)
		target_node->next->prev = target_node->prev;
	if (target_node->prev != NULL)
		target_node->prev->next = target_node->next;
	return (target_node);
}