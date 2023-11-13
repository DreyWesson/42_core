/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:08:03 by loandrad          #+#    #+#             */
/*   Updated: 2023/11/12 00:52:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static int	rotate_left_right(t_data *data, double rotspeed)
{
	double		tmp_x;

	tmp_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(rotspeed)
		- data->player.dir_y * sin(rotspeed);
	data->player.dir_y
		= tmp_x * sin(rotspeed) + data->player.dir_y * cos(rotspeed);
	tmp_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rotspeed)
		- data->player.plane_y * sin(rotspeed);
	data->player.plane_y
		= tmp_x * sin(rotspeed) + data->player.plane_y * cos(rotspeed);
	return (1);
}

int	rotate_player(t_data *data, double rotdir)
{
	int		moved;
	double	rotspeed;

	moved = 0;
	rotspeed = ROT_SPEED * rotdir;
	moved += rotate_left_right(data, rotspeed);
	return (moved);
}
