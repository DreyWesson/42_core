/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:39:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 13:40:12 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_node_tail(t_node** head_ref, t_node* new_node)
{
	t_node* last_node;

	if (*head_ref)
	{
		last_node = ft_last_node(*head_ref);
		new_node->prev = last_node;
		last_node->next = new_node;
	}
	else
		*head_ref = new_node;
}
