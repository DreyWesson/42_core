/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeaters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:53:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/12 19:35:50 by doduwole         ###   ########.fr       */
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

void	push_unsorted_only(t_node** x, t_node** y, char* ptr)
{
	int	last_3;
	t_node* tmp;

	tmp = *x;
	last_3 = ft_last_node(*x)->prev->prev->value;
	while (tmp)
	{
		// printf("leftover %d\n", leftover);
		if (tmp->value == last_3)
			break;
		if (is_cyclic(x))
			break;
		push(x, y, ptr);
		printf("unsorted %d %d\n", last_3, tmp->value);
		tmp = tmp->next;
	}
}
