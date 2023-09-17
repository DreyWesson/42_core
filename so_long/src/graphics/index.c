/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:13:24 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/04 20:43:56 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	game_init(t_game *game, t_cell	**grid, t_details details)
{
	int	row;
	int	col;

	game->window_size.x = details.col_nbr * IMG_SIZE;
	game->window_size.y = details.row_nbr * IMG_SIZE;
	game->props = details;
	game->moves = 0;
	game->player.tile = &grid[details.pos.y][details.pos.x];
	game->collects = details.burger_nbr;
	game->mlx = mlx_init();
	col = game->window_size.x + IMG_SIZE / 2;
	row = game->window_size.y + IMG_SIZE / 2;
	game->window = mlx_new_window(game->mlx, col, row, "Ajala Travel");
	game->grid = grid;
	if (!game->window || !game->mlx)
		return (0);
	return (1);
}

/* Sets the frames of all animatios */
static void	anim_init(t_game *game)
{
	game->player.frame_count = 0;
	game->effect.counter = 0;
	game->effect.frames = 0;
	game->player.idle_frames = 42;
	game->player.action_frames = 21;
	game->collects_imgs.anim_frames = 42;
	game->effect.frames = 7;
}

int	build_graphics(t_game *game, t_cell **grid, t_details props)
{
	if (!game_init(game, grid, props) || !load_images(game))
		return (0);
	anim_init(game);
	return (1);
}
