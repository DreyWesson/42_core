/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:33:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 09:52:32 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_nodes(t_node* a, t_node* b, char* tag)
{
	int	tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
	if (tag[0])
		ft_printf("%s\n", tag);
}

void	double_swap(t_node* a, t_node* b, t_node* x, t_node* y)
{
	swap_nodes(a, b, "");
	swap_nodes(x, y, "");
	ft_printf("ss\n");
}
