/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:36:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/22 12:57:33 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	ft_lstprint(void *ptr)
// {
// 	ft_printf("-> %d\n", (int)ptr);
// 	return ;
// }

// ERROR HANDLING
// [✅] check if str will be a proper number
// [✅] convert args to number
// [✅] take care of duplicates like 0==0000 +1 == 1 == 001 === 0001 // trim
// [✅] take care of too large integers
// [✅] keep only one of all equal numbers
// [💀] first arg should be on top of the stack
// [💀] smallest num at the top
// [💀] separate instructions by a '\n'



t_node* del_duplicates(t_node* head)
{
	t_node* current_node;
	t_node* iterator_node;
	t_node* rest_node;

	if (head == NULL || head->next == NULL)
		return (NULL);
	current_node = head;
	while (current_node)
	{
		iterator_node = current_node->next;
		while (iterator_node)
		{
			if (current_node->content == iterator_node->content)
			{
				rest_node = iterator_node->next;
				del_node(&iterator_node->prev, iterator_node);
				iterator_node->next = rest_node;
			}
			else
				iterator_node = iterator_node->next;
		}
		current_node = current_node->next;
	}
	return (head);
}

int	main(int argc, char** argv)
{
	int		i;
	t_node* head;

	i = 1;
	if (argc < 3)
	{
		ft_perror("Error\n");
		return (0);
	}
	head = (t_node*)malloc(sizeof(t_node));
	while (i < argc)
	{
		if (!ft_parser(argv[i], head))
		{
			ft_perror("Error\n");
			return (0);
		}
		i++;
	}
	del_duplicates(head);
	ft_printf("\n");
	ft_print_nodes(head);
	return (0);
}
