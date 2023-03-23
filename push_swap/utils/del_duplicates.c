/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:17:53 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 11:35:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node* del_duplicate_nodes(t_node** head_ref)
{
	t_node* current_node;
	t_node* iterator_node;
	t_node* rest_node;

	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return (NULL);
	current_node = *head_ref;
	while (current_node)
	{
		iterator_node = current_node->next;
		while (iterator_node)
		{
			if (current_node->value == iterator_node->value)
			{
				rest_node = iterator_node->next;
				free(del_node(&iterator_node->prev, iterator_node));
				iterator_node->next = rest_node;
			}
			else
				iterator_node = iterator_node->next;
		}
		current_node = current_node->next;
	}
	return (*head_ref);
}
