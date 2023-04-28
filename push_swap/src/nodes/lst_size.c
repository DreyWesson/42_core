/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:46:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/28 06:56:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	lst_size(t_node **head_ref)
{
	t_node	*tmp;
	int		size;

	if (!head_ref)
		return (0);
	size = 0;
	tmp = *head_ref;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
