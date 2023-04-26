/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:40:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/26 10:08:29 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_node_head(t_node **head_ref, t_node *new_node)
{
	new_node->next = *head_ref;
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	*head_ref = new_node;
}
