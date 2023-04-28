/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:39:08 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/28 06:56:48 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_node	*ft_last_node(t_node *head_ref)
{
	if (!head_ref)
		return (NULL);
	while (head_ref->next)
		head_ref = head_ref->next;
	return (head_ref);
}
