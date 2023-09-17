/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 03:02:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/04 20:38:17 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/so_long.h"

/* Input management. Called each time a key is pressed. */
int	input(int key, t_game *game)
{
	static int	moved;

	moved = game->moves;
	if (key == ESC)
		end_program(game);
	else if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		game->moves += move_player(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		game->moves += move_player(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		game->moves += move_player(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		game->moves += move_player(game, game->player.tile->right);
	else
		return (0);
	if (moved < game->moves)
		printf("Moves: %02d\n", game->moves);
	return (1);
}
