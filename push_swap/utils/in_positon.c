/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_positon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:47:17 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/25 00:30:40 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	in_position(t_node **stack_a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->list_idx == tmp->order_idx)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
