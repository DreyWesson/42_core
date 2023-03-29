/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:17:53 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 14:35:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_duplicates(t_node** head_ref)
{
	t_node* current_node;
	t_node* iterator_node;

	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return (1);
	current_node = *head_ref;
	while (current_node)
	{
		iterator_node = current_node->next;
		while (iterator_node)
		{
			if (current_node->value == iterator_node->value)
				return(1);
			iterator_node = iterator_node->next;
		}
		current_node = current_node->next;
	}
	return (0);
}
