/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:30:10 by ioduwole          #+#    #+#             */
/*   Updated: 2023/01/27 12:49:12 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(t_data *game)
{
	int	row;
	int	col;

	row = -1;
	if (game->potions == game->collected)
	{
		while (++row < game->row)
		{
			col = -1;
			while (++col < game->col)
				if (game->map[row][col] == 'E')
					ft_put_img(game, game->door[1], row, col);
		}
	}
	else
		return ;
}

void	is_exit(t_data *game, int row, int col)
{
	if (game->potions != game->collected)
	{
		ft_printf("You must retrieve all potions\n");
		change_position(game, row, col);
	}
	else
	{
		ft_printf("YOU WIN!!!\n");
		free_destroy(game);
	}
}

void	change_position(t_data *game, int row, int col)
{
	if (game->last_pos == '0')
		ft_put_img(game, game->space, game->player[0], game->player[1]);
	else if (game->last_pos == 'E')
		ft_put_img(game, game->door[0], game->player[0], game->player[1]);
	game->map[game->player[0]][game->player[1]] = game->last_pos;
	ft_put_img(game, game->character_img, row, col);
	game->last_pos = game->map[row][col];
	game->player[0] = row;
	game->player[1] = col;
	game->steps++;
	ft_printf("steps: %i\tHerbs: %i/%i\n", game->steps, game->collected, \
			game->potions);
}
