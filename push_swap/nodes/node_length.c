/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:06:17 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/29 10:13:46 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int node_length(t_node** head_ref)
{
	t_node* tmp;
	int i;

	i = 0;
	if (!head_ref)
		return (0);
	tmp = *head_ref;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
