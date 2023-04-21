/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeaters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:53:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/21 14:20:00 by doduwole         ###   ########.fr       */
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
	t_node* tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->list_idx == tmp->order_idx)
		{
			tmp = tmp->next;
			rotate(&tmp, "ra");
		}
		else
			push(&tmp, stack_b, "pb");
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
