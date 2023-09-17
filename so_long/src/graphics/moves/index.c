/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 07:32:27 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/04 20:46:30 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	to_collectible(t_game *game, t_cell *tile)
{
	tile->type = EMPTY;
	game->collects--;
	effect_anime(&game->effect, tile->position);
	action_anime(&game->player);
	to_empty(game, tile);
}

void	to_exit(t_game *game, t_cell *tile)
{
	effect_anime(&game->effect, tile->position);
	game->collects = -1;
	print_end(++game->moves);
	end_program(game);
}

void	to_empty(t_game *game, t_cell *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

int	move_player(t_game *game, t_cell *tile)
{
	if (tile->type == EMPTY)
		return (to_empty(game, tile), 1);
	else if (tile->type == COLLECTABLE)
		return (to_collectible(game, tile), 1);
	else if (tile->type == EXIT && game->collects <= 0)
		return (to_exit(game, tile), 1);
	return (0);
}
