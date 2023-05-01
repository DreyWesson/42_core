/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:34:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/01 13:22:56 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push(t_node **src_ref, t_node **dest_ref, char *tag, int output)
{
	t_node	*deleted_node;

	deleted_node = del_node(src_ref, *src_ref);
	add_node_head(dest_ref, deleted_node);
	if (output && tag[0])
		ft_printf("%s\n", tag);
}
