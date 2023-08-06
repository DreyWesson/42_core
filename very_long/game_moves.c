/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:56:54 by ioduwole          #+#    #+#             */
/*   Updated: 2023/01/26 16:13:48 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_destroy(t_data *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->space);
	mlx_destroy_image(game->mlx, game->character[0]);
	mlx_destroy_image(game->mlx, game->character[1]);
	mlx_destroy_image(game->mlx, game->potion);
	mlx_destroy_image(game->mlx, game->door[0]);
	mlx_destroy_image(game->mlx, game->door[1]);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	clear_game(game);
	exit(0);
}

void	move_character(t_data *game, int row, int col)
{
	if (game->map[row][col] == '1')
		return ;
	else if (game->map[row][col] == '0' || game->map[row][col] == 'C')
	{
		if (game->map[row][col] == 'C')
		{
			game->map[row][col] = '0';
			game->collected++;
			check_exit(game);
		}
		change_position(game, row, col);
	}
	else if (game->map[row][col] == 'E')
		is_exit(game, row, col);
}

void	key_hook2(int keycode, t_data *game)
{
	if (keycode == KEY_D)
	{
		if (game->direction != 'R')
		{
			game->character_img = game->character[0];
			ft_put_img(game, game->character_img, game->player[0],
				game->player[1]);
			game->direction = 'R';
		}
		else
			move_character(game, game->player[0], game->player[1] + 1);
	}
	else if (keycode == KEY_A)
	{
		if (game->direction != 'L')
		{
			game->character_img = game->character[1];
			ft_put_img(game, game->character_img, game->player[0],
				game->player[1]);
			game->direction = 'L';
		}
		else
			move_character(game, game->player[0], game->player[1] - 1);
	}
}

int	ft_key_hook(int keycode, t_data *game)
{
	if (keycode == ESC_KEY)
		free_destroy(game);
	else if (keycode == KEY_A || keycode == KEY_D)
		key_hook2(keycode, game);
	else if (keycode == KEY_W)
		move_character(game, game->player[0] - 1, game->player[1]);
	else if (keycode == KEY_S)
		move_character(game, game->player[0] + 1, game->player[1]);
	return (0);
}
