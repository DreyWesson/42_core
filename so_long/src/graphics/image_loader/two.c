/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 07:33:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/30 16:55:24 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

int	west_wall(t_game *game, int *x, int *y)
{
	game->wall_imgs.west = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/west_wall.xpm", x, y);
	return (west_wall_error(game->wall_imgs));
}

int	east_wall(t_game *game, int *x, int *y)
{
	game->wall_imgs.east = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/east_wall.xpm", x, y);
	return (east_wall_error(game->wall_imgs));
}

int	south_wall(t_game *game, int *x, int *y)
{
	game->wall_imgs.south = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/south_wall.xpm", x, y);
	game->wall_imgs.south_east = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/south_east.xpm", x, y);
	game->wall_imgs.south_west = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/south_west.xpm", x, y);
	return (south_wall_error(game->wall_imgs));
}

int	north_wall(t_game *game, int *x, int *y)
{
	game->wall_imgs.north = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/north_wall.xpm", x, y);
	game->wall_imgs.block = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/wall.xpm", x, y);
	game->wall_imgs.north_west = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/north_west.xpm", x, y);
	game->wall_imgs.north_east = mlx_xpm_file_to_image(game->mlx,
			"./inc/sprites/north_east.xpm", x, y);
	return (north_wall_error(game->wall_imgs));
}
