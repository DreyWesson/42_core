/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 07:28:12 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/30 11:09:34 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

static void	draw_image(t_game game)
{
	t_cell	cell;
	t_axis	pos;

	cell = game.current_cell;
	pos = cell.position;
	if (cell.type == WALL)
		draw_wall(game, pos);
	else if (cell.type == EXIT)
		draw_doors(game, pos);
	else if (cell.type == COLLECTABLE)
		draw_collectible(game, pos);
	else if (cell.type == PLAYER)
		draw_player(game, pos);
}

static void	draw_effect(t_game game)
{
	if (game.effect.counter < game.effect.frames)
		mlx_put_image_to_window(game.mlx, game.window,
			game.effect.img,
			game.effect.pos.x, game.effect.pos.y);
}

// Writes the number of moves on the window
static void	draw_text(t_game game)
{
	char	*str;

	str = ft_itoa(game.moves);
	str = ft_strjoin("Moves: ", str);
	mlx_string_put(game.mlx, game.window,
		game.window_size.x - IMG_SIZE,
		IMG_SIZE - IMG_SIZE / 1.5,
		15921152, str);
	free(str);
}

// Puts map on the window
void	render(t_game game)
{
	int		x;
	int		y;

	y = 0;
	mlx_clear_window(game.mlx, game.window);
	while (y < game.props.row_nbr)
	{
		x = 0;
		while (x < game.props.col_nbr)
		{
			game.current_cell = game.grid[y][x];
			draw_image(game);
			draw_effect(game);
			x++;
		}
		y++;
	}
	draw_text(game);
}
