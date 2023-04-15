/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:36:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/15 15:01:14 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	t_node** stack_a;
	t_node** stack_b;

	if (argc < 3)
		return (0);
	stack_a = (t_node**)malloc(sizeof(t_node*));
	stack_b = (t_node**)malloc(sizeof(t_node*));
	if (!validator(argc, argv, stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		ft_perror("Error\n");
		return (0);
	}
	if (is_sorted(stack_a))
		return (0);
	sort_router(stack_a, stack_b);
	// ft_print_nodes(stack_a);
	return (0);
}
// TEST ACTIONS
// dummystack(stack_b);
// swap_nodes(*stack_a, (*stack_a)->next); <= sa
// swap_nodes(*stack_b, (*stack_b)->next); <= sb
// double_swap(*stack_a, (*stack_a)->next, *stack_b, (*stack_b)->next); <= sa + sb
// push(stack_a, stack_b);  <= pa
// push(stack_b, stack_a);  <= pb
// rotate(stack_a); <= ra
// rotate(stack_b); <= rb
// double_rotate(stack_a, stack_b);
// reverse_rotate(stack_a);
// double_reverse(stack_a, stack_b);
// ft_printf("Is Sorted");
// ft_printf("%d\n", stack_size);
// 1 2 3 5 4