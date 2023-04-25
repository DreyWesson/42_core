/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:34:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/25 17:41:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **src_ref, t_node **dest_ref, char* tag)
{
	t_node	*deleted_node;

	deleted_node = del_node(src_ref, *src_ref);
	add_node_head(dest_ref, deleted_node);
	if (tag[0])
		ft_printf("%s\n", tag);
}

void	push_unsorted_only(t_node **x, t_node **y, char *ptr)
{
	int		last_3;
	t_node	*tmp;

	tmp = *x;
	last_3 = ft_last_node(*x)->prev->prev->value;
	while (tmp)
	{
		push(x, y, ptr);
		if (is_cyclic(x) || (*x)->value == last_3)
			break ;
	}
	if (lst_size(x) == 3 && (!is_sorted(x) && !is_cyclic(x)))
		sort_three_max(x, 'y');
}
