/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_router.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:03:12 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/28 06:59:25 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_router(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;

	stack_size = lst_size(stack_a);
	if (stack_size <= 3)
		sort_three_max(stack_a, 'n');
	else if (stack_size > 3)
		sort_more(stack_a, stack_b);
}
