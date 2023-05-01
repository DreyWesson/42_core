/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:33:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/01 15:10:16 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap_nodes(t_node *a, t_node *b, char *tag, int output)
{
	int	tmp;

	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
	if (output && tag[0])
		ft_printf("%s\n", tag);
}

void	double_swap(t_node *a, t_node *b, int output)
{
	swap_nodes(a, a->next, "", output);
	swap_nodes(b, b->next, "", output);
	if (output)
		ft_printf("ss\n");
}
