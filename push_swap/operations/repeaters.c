/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeaters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:53:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/22 19:47:34 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	repeat_rotate(t_node** x, int num, char* ptr)
{
	int	i;

	i = 0;
	while (i < num)
	{
		rotate(x, ptr);
		i++;
	}
}

void	repeat_push(t_node** x, t_node** y, int num, char* ptr)
{
	int	i;

	i = 0;
	while (i < num)
	{
		push(x, y, ptr);
		i++;
	}
}

void	repeat_reverse(t_node** x, int num, char* ptr)
{
	int	i;

	i = 0;
	while (i < num)
	{
		reverse_rotate(x, ptr);
		i++;
	}
}

void pick_sorted(t_node** stack_a, t_node** stack_b)
{
	int last_val;

	last_val = ft_last_node(*stack_a)->value;
	while (*stack_a)
	{
		if ((*stack_a)->value == last_val)
		{
			if ((*stack_a)->list_idx != (*stack_a)->order_idx)
				push(stack_a, stack_b, "pb");
			break;
		}
		if ((*stack_a)->list_idx == (*stack_a)->order_idx)
			rotate(stack_a, "ra");
		else
			push(stack_a, stack_b, "pb");
	}
}

void	push_unsorted_only(t_node** x, t_node** y, char* ptr)
{
	int	last_3;
	t_node* tmp;

	if (in_position(x) > 3)
		return pick_sorted(x, y);
	tmp = *x;
	last_3 = ft_last_node(*x)->prev->prev->value;
	while (tmp)
	{
		if (is_cyclic(x) || (*x)->value == last_3)
			break;
		push(x, y, ptr);
	}
}
