/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:36:32 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 21:38:44 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_nodes(t_node** head_ref)
{
	t_node* tmp;

	if (!head_ref)
		return;
	tmp = *head_ref;
	while (tmp)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
