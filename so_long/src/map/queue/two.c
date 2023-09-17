/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:08:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 17:18:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	print_node(t_nodes *head, int col_nbr)
{
	t_nodes	*tmp;

	tmp = head;
	while (tmp)
	{
		printf(
			"value: %c, x: %d, y: %d, status: %c\n",
			tmp->cell->val,
			tmp->cell->x_axis,
			tmp->cell->y_axis,
			tmp->cell->status
			);
		if (col_nbr - 1 == tmp->cell->x_axis)
			printf("\n");
		tmp = tmp->next;
	}
}
