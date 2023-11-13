/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:21:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 13:02:52 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	print_map(t_data *data, char *str)
{
	printf("\033[1;33m""\n%s:\n""\033[0m", str);
	print_array_2d_newline(data->map);
	printf("\n");
}

static void	print_data_helper(t_data *data)
{
	printf("win_height: %d\n", data->win_height);
	printf("win_width: %d\n", data->win_width);
	printf("col_ceiling %d %d %d\n", data->col_ceiling[0],
		data->col_ceiling[1], data->col_ceiling[2]);
	printf("col_floor %d %d %d\n", data->col_floor[0],
		data->col_floor[1], data->col_floor[2]);
	printf("col_ceiling_int %d\n", data->col_ceiling_int);
	printf("col_floor_int %d\n", data->col_floor_int);
	printf("PLAYER dir: %c, x: %d, y: %d, view_y: %f, view_x: %f, plane_y: %f, \
		plane_x: %f, dir_x: %f, dir_y: %f\n", data->player.dir, data->player.x, \
		data->player.y, data->player.pos_x, data->player.pos_y, \
		data->player.plane_y, data->player.plane_x, data->player.dir_x, \
		data->player.dir_y);
	printf("tile_h %d\n", data->tile_h);
	printf("tile_w %d\n", data->tile_w);
	printf("tex_index: %d, tex_step: %f, tex_pos: %f\n", data->tex_index,
		data->tex_step, data->tex_pos);
}

void	print_all_data(t_data *data)
{
	printf("cub_path: %s cub_height: %d\n", data->cub_path, data->cub_height);
	printf("map_height %d map_width %d\n", data->map_height, data->map_width);
	printf("north_tex: %s\n", data->north_tex);
	printf("south_tex: %s\n", data->south_tex);
	printf("east_tex: %s\n", data->east_tex);
	printf("west_tex: %s\n", data->west_tex);
	printf("textures: %d\n", data->textures[0][0]);
	printf("textures: %d\n", data->textures[1][0]);
	printf("textures: %d\n", data->textures[2][0]);
	printf("textures: %d\n", data->textures[3][0]);
	printf("tex_size: %d\n", data->tex_size);
	printf("tex_x: %d\n", data->tex_x);
	printf("tex_y: %d\n", data->tex_y);
	print_data_helper(data);
}
