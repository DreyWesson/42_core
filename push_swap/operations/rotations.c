/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 15:16:50 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_node** head_ref)
{
	int deleted_value;
	t_node* deleted_node;

	deleted_node = del_node(head_ref, *head_ref);
	deleted_value = deleted_node->value;
	free(deleted_node);
	add_node_tail(head_ref, create_node(deleted_value));
}
void double_rotate(t_node** a, t_node** b)
{
	rotate(a);
	rotate(b);
}

void reverse_rotate(t_node** head_ref)
{
	t_node* last_node;
	int deleted_value;
	t_node* deleted_node;

	last_node = ft_last_node(*head_ref);
	deleted_node = del_node(head_ref, last_node);
	deleted_value = deleted_node->value;
	free(deleted_node);
	add_node_head(head_ref, create_node(deleted_value));
}

void double_reverse(t_node** a, t_node** b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
