/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:17:53 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 14:37:04 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int check_duplicates(t_node** head_ref)
{
	t_node* curr_node;
	t_node* itr_node;

	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return (1);
	curr_node = *head_ref;
	while (curr_node)
	{
		itr_node = curr_node->next;
		while (itr_node)
		{
			if (curr_node->value == itr_node->value)
				return(1);
			itr_node = itr_node->next;
		}
		curr_node = curr_node->next;
	}
	return (0);
}
