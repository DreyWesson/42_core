/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:32:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/22 23:23:03 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_nodes(t_node** head)
{
	t_node* tmp;
	if (!head)
		return;
	tmp = *head;
	while (tmp)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
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
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_node_tail(t_node** lst, t_node* new)
{
	t_node* last_node;

	if (*lst)
	{
		last_node = ft_last_node(*lst);
		new->prev = last_node;
		last_node->next = new;
	}
	else
		*lst = new;
}

void	add_node_head(t_node** lst, t_node* new_node)
{
	new_node->next = *lst;
	if ((*lst) != NULL)
		(*lst)->prev = new_node;
	*lst = new_node;
}