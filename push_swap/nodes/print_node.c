/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:36:32 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/26 10:10:28 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_nodes(t_node **head_ref, char ptr)
{
	t_node	*tmp;

	if (!head_ref)
		return ;
	tmp = *head_ref;
	while (tmp)
	{
		if (ptr == 'v')
			ft_printf("value: %d\n", tmp->value);
		else
			ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
// if (ptr == 'v')
// 	ft_printf("value: %d\norder_idx: %d\nlist_idx:
// 	%d\nexit_cost:%d\n target_cost: %d\noptimized:
// 	%d\npriority: %d\n\n",
// 	tmp->value,tmp->order_idx, tmp->list_idx,
// 	tmp->exit_cost,tmp->target_cost, tmp->optimized, tmp->priority);
// else
// 	ft_printf("%d ", tmp->value);