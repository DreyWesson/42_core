/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:54:56 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 00:35:19 by doduwole         ###   ########.fr       */
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

// void push(t_node* src, t_node* dest)
// {
// 	int deleted_content;

// 	deleted_content = del_node(&src, src)->next->content;
// 	add_node_tail(&dest, create_list(deleted_content));
// }
// push
// rotate
// double rotate
// reverse rotate
// double reverse rotate
