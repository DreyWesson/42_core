/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:34:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 14:18:04 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push(t_node** src_ref, t_node** dest_ref, char* tag)
{
	int deleted_value;
	t_node* deleted_node;

	deleted_node = del_node(src_ref, *src_ref);
	deleted_value = deleted_node->value;
	free(deleted_node);
	add_node_head(dest_ref, create_node(deleted_value));
	if (tag[0])
		ft_printf("%s\n", tag);
}
