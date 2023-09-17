/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 07:30:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/31 23:12:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/so_long.h"

int	end_program(t_game *game)
{
	free(game->mlx);
	free_grid(game->grid, game->props.row_nbr, 0);
	exit(0);
}

int	reset(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->props.row_nbr)
	{
		x = 0;
		while (x < game->props.col_nbr)
		{
			game->grid[y][x].type = game->grid[y][x].cache;
			if (game->grid[y][x].type == PLAYER)
				game->player.tile = &game->grid[y][x];
			x++;
		}
		y++;
	}
	game->moves = 0;
	game->collects = game->props.burger_nbr;
	return (0);
}
