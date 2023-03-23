/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:43:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 21:43:26 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_sorted(t_node** head_ref, int* size)
{
	t_node* tmp;

	if (!head_ref)
		return (0);
	tmp = *head_ref;
	while (tmp)
	{
		*size += 1;
		if (tmp->prev && tmp->prev->value > tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
