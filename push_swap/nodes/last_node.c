/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:39:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:56:56 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_last_node(t_node *head_ref)
{
	if (!head_ref)
		return (NULL);
	while (head_ref->next)
		head_ref = head_ref->next;
	return (head_ref);
}
