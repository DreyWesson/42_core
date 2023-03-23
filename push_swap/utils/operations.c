/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:54:56 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 11:09:22 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_nodes(t_node* a, t_node* b)
{
	int	tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

void	double_swap(t_node* a, t_node* b, t_node* x, t_node* y)
{
	swap_nodes(a, b);
	swap_nodes(x, y);
}

void push(t_node** src, t_node** dest)
{
	int deleted_content;
	t_node* deleted_node;

	deleted_node = del_node(src, *src);
	deleted_content = deleted_node->content;
	free(deleted_node);
	add_node_head(dest, create_list(deleted_content));
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
