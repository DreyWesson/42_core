/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:54:56 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/22 14:50:14 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// swap
void	swap_nodes(t_node* a, t_node* b)
{
	int	tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}
// double swap
// push
// rotate
// double rotate
// reverse rotate
// double reverse rotate
