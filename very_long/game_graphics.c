/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:03:23 by ioduwole          #+#    #+#             */
/*   Updated: 2023/01/26 12:59:46 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_data *game, void *img, int row, int col)
{
	mlx_put_image_to_window(game->mlx, game->win, \
			img, SIZE * col, SIZE * row);
}

void	init_map(t_data *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->row)
	{
		col = -1;
		while (++col < game->col)
		{
			if (game->map[row][col] == '1')
				ft_put_img(game, game->wall, row, col);
			else if (game->map[row][col] == '0')
				ft_put_img(game, game->space, row, col);
			else if (game->map[row][col] == 'E')
				ft_put_img(game, game->door[0], row, col);
			else if (game->map[row][col] == 'P')
				ft_put_img(game, game->character_img, row, col);
			else if (game->map[row][col] == 'C')
				ft_put_img(game, game->potion, row, col);
		}
	}
}

void	build_wall_door(t_data *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, \
			"./img/xpm/wall.xpm", &game->img_wh, &game->img_wh);
	game->space = mlx_xpm_file_to_image(game->mlx, \
			"./img/xpm/floor.xpm", &game->img_wh, &game->img_wh);
	game->door[0] = mlx_xpm_file_to_image(game->mlx, \
			"./img/xpm/doorC.xpm", &game->img_wh, &game->img_wh);
	game->door[1] = mlx_xpm_file_to_image(game->mlx, \
			"./img/xpm/doorO.xpm", &game->img_wh, &game->img_wh);
}

void	build_game_potion(t_data *game)
{
	game->potion = mlx_xpm_file_to_image(game->mlx, \
			"./img/xpm/potion.xpm", &game->img_wh, &game->img_wh);
	game->character[0] = mlx_xpm_file_to_image(game->mlx, \
			"./img/xpm/character_right.xpm", &game->img_wh, &game->img_wh);
	game->character[1] = mlx_xpm_file_to_image(game->mlx, \
			"./img/xpm/character_left.xpm", &game->img_wh, &game->img_wh);
	if (game->player[1] <= (game->col / 2))
	{
		game->character_img = game->character[0];
		game->direction = 'R';
	}
	else if (game->player[1] > (game->col / 2))
	{
		game->character_img = game->character[1];
		game->direction = 'L';
	}
}

void	build_graphics(t_data *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, SIZE * game->col, \
			SIZE * game->row, "The Journey of Nas");
	game->last_pos = '0';
	build_game_potion(game);
	build_wall_door(game);
	init_map(game);
	ft_printf("Steps: %i\tPotions: %i/%i\n", game->steps, game->potions, \
			game->collected);
	mlx_hook(game->win, 2, 1L << 0, ft_key_hook, game);
	mlx_hook(game->win, 17, 1L << 2, free_destroy, game);
	mlx_loop(game->mlx);
}
