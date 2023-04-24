/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:36:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/25 00:42:32 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_both(t_node **x, t_node **y)
{
	free_stack(x);
	free_stack(y);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 3)
		return (0);
	stack_a = (t_node **)malloc(sizeof(t_node *));
	stack_b = (t_node **)malloc(sizeof(t_node *));
	if (!validator(argc, argv, stack_a))
	{
		free_both(stack_a, stack_b);
		ft_perror("Error\n");
		return (0);
	}
	if (is_sorted(stack_a))
		return (0);
	sort_router(stack_a, stack_b);
	free_both(stack_a, stack_b);
	return (0);
}
