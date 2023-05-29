/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:36:32 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/05 20:56:18 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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
