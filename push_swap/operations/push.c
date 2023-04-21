/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:34:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/21 10:58:12 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push(t_node** src_ref, t_node** dest_ref, char* tag)
{
	// int deleted_value;
	t_node* deleted_node;

	deleted_node = del_node(src_ref, *src_ref);
	deleted_node->next = NULL;
	deleted_node->prev = NULL;
	// deleted_value = deleted_node->value;
	// free(deleted_node);
	add_node_head(dest_ref, deleted_node);
	if (tag[0])
		ft_printf("%s\n", tag);
}
