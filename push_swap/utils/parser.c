/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:48:23 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/21 21:53:39 by doduwole         ###   ########.fr       */
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
// void ft_print_nodes(t_node* head)
// {
// 	if (!head)
// 		return;
// 	while (head)
// 	{
// 		ft_printf("%d\n", head->content);
// 		head = head->next;
// 	}
// }

long	ft_atoi_lg(const char* str)
{
	long	i;
	long	nbr;
	int		is_neg;

	i = 0;
	nbr = 0;
	is_neg = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
		is_neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if (is_neg == 1)
		return (-nbr);
	return (nbr);
}

int	ft_parser(char* str, t_node* head)
{
	int	i;
	long nbr;

	i = 0;
	if (ft_strchr("+-", str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	nbr = ft_atoi_lg(str);
	if (nbr < -2147483648 || nbr > 2147483647)
		return (0);
	add_node_tail(&head, create_list(nbr));

	return (1);
}
