/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeaters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:53:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/28 06:57:27 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	repeat_rotate(t_node **x, int num, char *ptr)
{
	int	i;

	i = 0;
	while (i < num)
	{
		rotate(x, ptr);
		i++;
	}
}

void	repeat_push(t_node **x, t_node **y, int num, char *ptr)
{
	int	i;

	i = 0;
	while (i < num)
	{
		push(x, y, ptr);
		i++;
	}
}

void	repeat_reverse(t_node **x, int num, char *ptr)
{
	int	i;

	i = 0;
	while (i < num)
	{
		reverse_rotate(x, ptr);
		i++;
	}
}

void	repeat_double_rotate(t_node **x, t_node **y, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		double_rotate(x, y);
		i++;
	}
}

void	repeat_double_reverse(t_node **x, t_node **y, int num)
{
	while (num < 0)
	{
		double_reverse(x, y);
		num++;
	}
}
