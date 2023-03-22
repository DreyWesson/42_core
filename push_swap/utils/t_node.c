/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:32:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/22 15:19:58 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_nodes(t_node* head)
{
	if (!head)
		return;
	while (head)
	{
		if (head->prev)
			ft_printf("%d ", head->content);
		head = head->next;
	}
}

t_node* del_node(t_node** prev_node, t_node* del)
{
	if (!*prev_node || !del)
		return (NULL);
	if (*prev_node == del)
		*prev_node = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	return (del);
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

t_node* ft_last_node(t_node* lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	add_node_tail(t_node** lst, t_node* new)
{
	t_node* last_node;

	if (*lst)
	{
		last_node = ft_last_node(*lst);
		last_node->next = new;
		new->prev = last_node;
	}
	else
		*lst = new;
}
