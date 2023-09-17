/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:13:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 22:58:36 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

int	draw_corner(t_game game, t_axis pos)
{
	if (pos.x == 0
		&& pos.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.north_west, pos.x, pos.y);
	else if (pos.x == 0
		&& pos.y == game.window_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.south_west, pos.x, pos.y);
	else if (pos.x == game.window_size.x - IMG_SIZE
		&& pos.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.north_east, pos.x, pos.y);
	else if (pos.x == game.window_size.x - IMG_SIZE
		&& pos.y == game.window_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.south_east, pos.x, pos.y);
	else
		return (0);
	return (1);
}

int	draw_sides(t_game game, t_axis pos)
{
	if (pos.x == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.west, pos.x, pos.y);
	else if (pos.x == game.window_size.x - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.east, pos.x, pos.y);
	else if (pos.y == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.north, pos.x, pos.y);
	else if (pos.y == game.window_size.y - IMG_SIZE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.wall_imgs.south, pos.x, pos.y);
	else
		return (0);
	return (1);
}

// /* Draws the corresponding sprite for the wall at <pos> */
void	draw_wall(t_game game, t_axis pos)
{
	if (draw_corner(game, pos) || draw_sides(game, pos))
		return ;
	mlx_put_image_to_window(game.mlx, game.window,
		game.wall_imgs.block, pos.x, pos.y);
}

void	draw_doors(t_game game, t_axis pos)
{
	if (game.collects == 0)
		mlx_put_image_to_window(game.mlx, game.window,
			game.door_close_img, pos.x, pos.y);
	else
		mlx_put_image_to_window(game.mlx, game.window,
			game.door_open_img, pos.x, pos.y);
}

void	draw_collectible(t_game game, t_axis pos)
{
	mlx_put_image_to_window(game.mlx, game.window,
		game.collects_imgs.current_img, pos.x, pos.y);
}
