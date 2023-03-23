/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:54:56 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 11:35:40 by doduwole         ###   ########.fr       */
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

// void double_push(t_node** src, t_node** dest)
// {

// }

// rotate
// void rotate()
// {

// }
// double rotate
// reverse rotate
// double reverse rotate
