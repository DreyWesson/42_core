/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:38:57 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/26 10:39:34 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	helper(t_node *highest, t_node **stack_a, t_node **stack_b, char ptr)
{
	int	num;

	num = highest->optimized;
	if (ptr == 'r')
		repeat_double_rotate(stack_a, stack_b, num);
	else
		repeat_double_reverse(stack_a, stack_b, num);
	highest->exit_cost += (num * -1);
	highest->target_cost += (num * -1);
}
