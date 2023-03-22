/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:17:53 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/22 13:18:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node* del_duplicate_nodes(t_node* head)
{
	t_node* current_node;
	t_node* iterator_node;
	t_node* rest_node;

	if (head == NULL || head->next == NULL)
		return (NULL);
	current_node = head;
	while (current_node)
	{
		iterator_node = current_node->next;
		while (iterator_node)
		{
			if (current_node->content == iterator_node->content)
			{
				rest_node = iterator_node->next;
				del_node(&iterator_node->prev, iterator_node);
				iterator_node->next = rest_node;
			}
			else
				iterator_node = iterator_node->next;
		}
		current_node = current_node->next;
	}
	return (head);
}