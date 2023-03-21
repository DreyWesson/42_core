/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:36:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/21 20:50:32 by doduwole         ###   ########.fr       */
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
// [] take care of too large integers
// [💀] keep only one of all equal numbers
// [💀] first arg should be on top of the stack
// [💀] smallest num at the top
// [💀] separate instructions by a '\n'

void ft_printnodes(t_node* head)
{
	if (!head)
		return;
	while (head)
	{
		ft_printf("%d\n", head->content);
		head = head->next;
	}

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
	ft_printnodes(head);
	return (0);
}
