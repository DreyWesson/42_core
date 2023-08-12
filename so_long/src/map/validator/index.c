/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:44:42 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/12 16:45:18 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	validate_map(char **map, int line_nbr)
{
	int		i;
	int		j;
	int		col_nbr;
	t_qty	*qty;
	t_coord	start_pos;

	i = 0;
	col_nbr = 0;
	qty = malloc(sizeof(t_qty));
	default_quant(qty);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			validate_composition(map[i][j], qty);
			validate_walls(map[i], line_nbr, j, i);
			if (map[i][j] == 'P')
				start_pos = save_start(i, j);
			j++;
		}
		validate_shape(line_nbr, &col_nbr, i, j);
		i++;
	}
	(void)start_pos;
	printf("%d %d\n", start_pos.x, start_pos.y);
	check_quant(qty);
}