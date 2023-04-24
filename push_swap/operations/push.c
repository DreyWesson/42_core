/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:34:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/25 00:09:05 by doduwole         ###   ########.fr       */
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

void	pick_sorted(t_node	**stack_a, t_node	**stack_b)
{
	int	last_val;

	last_val = ft_last_node(*stack_a)->value;
	while (*stack_a)
	{
		if ((*stack_a)->value == last_val)
		{
			if ((*stack_a)->list_idx != (*stack_a)->order_idx)
				push(stack_a, stack_b, "pb");
			break ;
		}
		if ((*stack_a)->list_idx == (*stack_a)->order_idx)
			rotate(stack_a, "ra");
		else
			push(stack_a, stack_b, "pb");
	}
}

void	push_unsorted_only(t_node **x, t_node **y, char *ptr)
{
	int		last_3;
	t_node	*tmp;

	if (in_position(x) > 3)
		return pick_sorted(x, y);
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
