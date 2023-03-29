/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 10:40:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rotate(t_node** head_ref, char* tag)
{
	int deleted_value;
	t_node* deleted_node;

	deleted_node = del_node(head_ref, *head_ref);
	deleted_value = deleted_node->value;
	free(deleted_node);
	add_node_tail(head_ref, create_node(deleted_value));
	if (tag[0])
		ft_printf("%s\n", tag);
}

void double_rotate(t_node** a, t_node** b)
{
	rotate(a, "");
	rotate(b, "");
	ft_printf("rr\n");
}

void reverse_rotate(t_node** head_ref, char* tag)
{
	t_node* last_node;
	int deleted_value;
	t_node* deleted_node;

	last_node = ft_last_node(*head_ref);
	deleted_node = del_node(head_ref, last_node);
	deleted_value = deleted_node->value;
	free(deleted_node);
	add_node_head(head_ref, create_node(deleted_value));
	if (tag[0])
		ft_printf("%s\n", tag);
}

void double_reverse(t_node** a, t_node** b)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
	ft_printf("rrr\n");
}
