/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:48:23 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/21 20:48:54 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node* create_list(int content)
{
	t_node* head;

	head = (t_node*)malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
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
	}
	else
		*lst = new;
}

int	ft_parser(char* str, t_node* head)
{
	int	i;

	i = 0;
	if (ft_strchr("+-", str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	ft_printf("<%d>\n", ft_atoi(str));
	add_node_tail(&head, create_list(ft_atoi(str)));
	return (1);
}
