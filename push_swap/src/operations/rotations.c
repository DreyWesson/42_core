/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/01 13:28:34 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate(t_node **head_ref, char *tag, int output)
{
	t_node	*deleted_node;

	deleted_node = del_node(head_ref, *head_ref);
	add_node_tail(head_ref, deleted_node);
	if (output && tag[0])
		ft_printf("%s\n", tag);
}

void	double_rotate(t_node **a, t_node **b, int output)
{
	rotate(a, "", output);
	rotate(b, "", output);
	ft_printf("rr\n");
}

void	reverse_rotate(t_node **head_ref, char *tag, int output)
{
	t_node	*last_node;
	t_node	*deleted_node;

	last_node = ft_last_node(*head_ref);
	deleted_node = del_node(head_ref, last_node);
	add_node_head(head_ref, deleted_node);
	if (output && tag[0])
		ft_printf("%s\n", tag);
}

void	double_reverse(t_node **a, t_node **b, int output)
{
	reverse_rotate(a, "", output);
	reverse_rotate(b, "", output);
	if (output)
		ft_printf("rrr\n");
}
