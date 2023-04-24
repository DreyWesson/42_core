/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:34:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/22 19:52:53 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void push(t_node** src_ref, t_node** dest_ref, char* tag)
{
	t_node* deleted_node;

	deleted_node = del_node(src_ref, *src_ref);
	add_node_head(dest_ref, deleted_node);
	if (tag[0])
		ft_printf("%s\n", tag);
}
