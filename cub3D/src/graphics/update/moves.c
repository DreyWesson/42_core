/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:05:52 by loandrad          #+#    #+#             */
/*   Updated: 2023/11/12 01:17:33 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static bool	is_valid_pos(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->map_width - 1.25
		|| y < 0.25 || y >= data->map_height -0.25)
		return (false);
	return (true);
}

static int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

static int	move_set(t_data *data, double x, double y)
{
	double	new_x;
	double	new_y;

	new_x = x;
	new_y = y;
	return (validate_move(data, new_x, new_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_set(data,
				data->player.pos_x + data->player.dir_x * MOVE_SPEED,
				data->player.pos_y + data->player.dir_y * MOVE_SPEED);
	if (data->player.move_y == -1)
		moved += move_set(data,
				data->player.pos_x - data->player.dir_x * MOVE_SPEED,
				data->player.pos_y - data->player.dir_y * MOVE_SPEED);
	if (data->player.move_x == -1)
		moved += move_set(data,
				data->player.pos_x + data->player.dir_y * MOVE_SPEED,
				data->player.pos_y - data->player.dir_x * MOVE_SPEED);
	if (data->player.move_x == 1)
		moved += move_set(data,
				data->player.pos_x - data->player.dir_y * MOVE_SPEED,
				data->player.pos_y + data->player.dir_x * MOVE_SPEED);
	if (data->player.rotate != 0)
		moved += rotate_player(data, data->player.rotate);
	return (moved);
}
