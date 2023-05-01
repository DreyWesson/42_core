/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeaters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:53:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/01 15:05:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	repeat_rotate(t_node **x, int num, char *ptr, int output)
{
	int	i;

	i = 0;
	while (i < num)
	{
		rotate(x, ptr, output);
		i++;
	}
}

void	repeat_push(t_stacks *stacks, int num, char *ptr, int output)
{
	int		i;
	t_node	**x;
	t_node	**y;

	i = 0;
	x = stacks->stack_a;
	y = stacks->stack_b;
	while (i < num)
	{
		push(x, y, ptr, output);
		i++;
	}
}

void	repeat_reverse(t_node **x, int num, char *ptr, int output)
{
	int	i;

	i = 0;
	while (i < num)
	{
		reverse_rotate(x, ptr, output);
		i++;
	}
}

void	repeat_double_rotate(t_node **x, t_node **y, int num, int output)
{
	int	i;

	i = 0;
	while (i < num)
	{
		double_rotate(x, y, output);
		i++;
	}
}

void	repeat_double_reverse(t_node **x, t_node **y, int num, int output)
{
	while (num < 0)
	{
		double_reverse(x, y, output);
		num++;
	}
}
