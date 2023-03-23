/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:38:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 13:45:16 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node* create_node(int value)
{
	t_node* head;

	head = (t_node*)malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->value = value;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}
