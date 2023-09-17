/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:36:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/31 22:56:21 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

t_nodes	*create_node(t_cell *cell)
{
	t_nodes	*node;

	node = (t_nodes *)malloc(sizeof(t_nodes));
	if (!node)
		return (NULL);
	node->cell = cell;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_nodes	*last_node(t_nodes *head)
{
	t_nodes	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	del_node(t_nodes **head)
{
	t_nodes	*tmp;

	if (!(*head)->next)
	{
		free(*head);
		*head = NULL;
		return ;
	}
	tmp = (*head)->next;
	free(*head);
	tmp->prev = NULL;
	*head = tmp;
}

void	add_tail_node(t_nodes **old, t_nodes *new)
{
	new->next = *old;
	if (*old)
		(*old)->prev = new;
	*old = new;
}

void	add_head_node(t_nodes **old, t_nodes *new)
{
	t_nodes	*tmp;

	if (*old == NULL)
	{
		*old = new;
		return ;
	}
	tmp = last_node(*old);
	new->prev = tmp;
	tmp->next = new;
}
