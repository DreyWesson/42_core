/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:36:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/22 14:54:49 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ERROR HANDLING
// [✅] check if str will be a proper number
// [✅] convert args to number
// [✅] take care of duplicates like 0==0000 +1 == 1 == 001 === 0001 // trim
// [✅] take care of too large integers
// [✅] keep only one of all equal numbers
// [✅] first arg should be on top of the stack
// [💀] smallest num at the top
// [💀] separate instructions by a '\n'


int helper(int argc, char** argv, t_node* head)
{
	int		i;

	i = 0;
	while (++i < argc)
		if (!ft_parser(argv[i], head))
			return (0);
	if (!del_duplicate_nodes(head)->next->next)
		return (0);
	return (1);
}

int	main(int argc, char** argv)
{
	t_node* head;

	if (argc < 3)
	{
		ft_perror("Error\n");
		return (0);
	}
	head = (t_node*)malloc(sizeof(t_node));
	if (!helper(argc, argv, head))
	{
		ft_perror("Error\n");
		return (0);
	}
	ft_print_nodes(head);
	swap_nodes(head->next, head->next->next);
	ft_printf("\n");
	ft_print_nodes(head);
	return (0);
}
