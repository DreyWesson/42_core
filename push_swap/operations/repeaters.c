/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeaters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:53:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/06 18:55:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void repeat_rotate(t_node** x, int num, char* ptr)
{
	int i;

	i = -1;
	while (++i < num)
		rotate(x, ptr);
}

void repeat_push(t_node** x, t_node** y, int num, char* ptr)
{
	int i;

	i = -1;
	while (++i < num)
		push(x, y, ptr);
}

void repeat_reverse(t_node** x, int num, char* ptr)
{
	int i;

	i = -1;
	while (++i < num)
		reverse_rotate(x, ptr);
}
