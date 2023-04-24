/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:13:31 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:56:27 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_node **head_ref)
{
	t_node	*tmp;

	if (!head_ref)
		return ;
	while (*head_ref)
	{
		tmp = (*head_ref)->next;
		free(*head_ref);
		*head_ref = tmp;
	}
}
