/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:54:56 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 13:24:33 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_nodes(t_node* a, t_node* b)
{
	int	tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

void	double_swap(t_node* a, t_node* b, t_node* x, t_node* y)
{
	swap_nodes(a, b);
	swap_nodes(x, y);
}

void push(t_node** src_ref, t_node** dest_ref)
{
	int deleted_value;
	t_node* deleted_node;

	deleted_node = del_node(src_ref, *src_ref);
	deleted_value = deleted_node->value;
	free(deleted_node);
	add_node_head(dest_ref, create_list(deleted_value));
}

// rotate
void rotate(t_node** head_ref)
{
	int deleted_value;
	t_node* deleted_node;

	deleted_node = del_node(head_ref, *head_ref);
	deleted_value = deleted_node->value;
	free(deleted_node);
	add_node_tail(head_ref, create_list(deleted_value));
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
	add_node_head(head_ref, create_list(deleted_value));
}

void double_reverse(t_node** a, t_node** b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
