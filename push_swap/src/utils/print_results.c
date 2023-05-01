/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:50:27 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/01 15:53:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	print_result(t_node **a, t_node **b)
{
	if (is_sorted(a) && !*b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
