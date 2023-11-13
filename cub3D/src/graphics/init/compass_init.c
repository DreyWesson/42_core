/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:59:50 by loandrad          #+#    #+#             */
/*   Updated: 2023/11/09 12:42:26 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static t_player	set_compass(double dir_x, double dir_y,
	double plane_x, double plane_y)
{
	t_player	player;

	ft_memset((void *)&player, 0, sizeof(player));
	player.dir_x = dir_x;
	player.dir_y = dir_y;
	player.plane_x = plane_x;
	player.plane_y = plane_y;
	return (player);
}

static void	set_player_data(t_data *data, t_player player)
{
	data->player.dir_x = player.dir_x;
	data->player.dir_y = player.dir_y;
	data->player.plane_x = player.plane_x;
	data->player.plane_y = player.plane_y;
}

void	handle_compass(t_data *data)
{
	if (data->player.dir == 'S')
		set_player_data(data, set_compass(0, 1, -0.66, 0));
	else if (data->player.dir == 'N')
		set_player_data(data, set_compass(0, -1, 0.66, 0));
	else if (data->player.dir == 'W')
		set_player_data(data, set_compass(-1, 0, 0, -0.66));
	else if (data->player.dir == 'E')
		set_player_data(data, set_compass(1, 0, 0, 0.66));
}
