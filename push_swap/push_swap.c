/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:36:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/03/23 11:26:58 by doduwole         ###   ########.fr       */
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


int helper(int argc, char** argv, t_node** head)
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
void dummystack(t_node** stack)
{
	int i = -1;
	int arr[4] = { 5, 6, 7, 8 };
	while (++i < 4)
		add_node_tail(stack, create_list(arr[i]));
}

int	main(int argc, char** argv)
{
	t_node** stack_a;
	t_node** stack_b;

	if (argc < 3)
	{
		ft_perror("Error\n");
		return (0);
	}
	stack_a = (t_node**)malloc(sizeof(t_node));
	stack_b = (t_node**)malloc(sizeof(t_node));
	if (!helper(argc, argv, stack_a))
	{
		ft_perror("Error\n");
		return (0);
	}
	dummystack(stack_b);

	// push(stack_a, stack_b);
	ft_print_nodes(stack_a);
	ft_print_nodes(stack_b);
	// free here
	return (0);
}
// TEST ACTIONS
	// swap_nodes(*stack_a, (*stack_a)->next); <= sa
	// swap_nodes(*stack_b, (*stack_b)->next); <= sb
	// double_swap(*stack_a, (*stack_a)->next, *stack_b, (*stack_b)->next); <= sa + sb
	// push(stack_a, stack_b);  <= pa
	// push(stack_b, stack_a);  <= pb
