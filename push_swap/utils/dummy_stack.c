/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:15:05 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 15:15:23 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void dummystack(t_node** stack)
{
	int i = -1;
	int arr[4] = { 5, 6, 7, 8 };
	while (++i < 4)
		add_node_tail(stack, create_node(arr[i]));
}
