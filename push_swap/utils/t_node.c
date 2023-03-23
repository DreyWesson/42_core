/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:32:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 11:23:01 by doduwole         ###   ########.fr       */
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
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

t_node* del_node(t_node** prev_node, t_node* target_node)
{
	if (!*prev_node || !target_node)
		return (NULL);
	if (*prev_node == target_node)
		*prev_node = target_node->next;
	if (target_node->next != NULL)
		target_node->next->prev = target_node->prev;
	if (target_node->prev != NULL)
		target_node->prev->next = target_node->next;
	return (target_node);
}

t_node* create_list(int content)
{
	t_node* head;

	head = (t_node*)malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

t_node* ft_last_node(t_node* head_ref)
{
	if (!head_ref)
		return (NULL);
	while (head_ref->next)
		head_ref = head_ref->next;
	return (head_ref);
}

void	add_node_tail(t_node** head_ref, t_node* new)
{
	t_node* last_node;

	if (*head_ref)
	{
		last_node = ft_last_node(*head_ref);
		new->prev = last_node;
		last_node->next = new;
	}
	else
		*head_ref = new;
}

void	add_node_head(t_node** head_ref, t_node* new_node)
{
	new_node->next = *head_ref;
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	*head_ref = new_node;
}
