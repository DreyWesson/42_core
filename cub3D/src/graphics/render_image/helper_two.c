/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 00:01:15 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/12 01:20:16 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	calc_x_coord_pl_facing_left_up(t_data *data, t_ray *ray)
{
	data->tex_step = 1.0 * data->tex_size / ray->line_height;
	data->tex_pos = (ray->draw_start - data->win_height / 2
			+ ray->line_height / 2) * data->tex_step;
}

void	handle_vert_wall_px(t_data *data, t_ray *ray, int x)
{
	int	y;
	int	color;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (data->tex_size - 1);
		data->tex_pos += data->tex_step;
		color = data->textures[data->tex_index][data->tex_size
			* data->tex_y + data->tex_x];
		if (data->tex_index == NORTH || data->tex_index == EAST)
			color = (color >> 1) & SHADOW;
		if (color > 0)
			data->tex_pixels[y][x] = color;
		y++;
	}
}
