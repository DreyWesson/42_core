/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:56:51 by loandrad          #+#    #+#             */
/*   Updated: 2023/11/12 17:02:10 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	set_texture_x_coord(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->tex_index = WEST;
		else
			data->tex_index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->tex_index = SOUTH;
		else
			data->tex_index = NORTH;
	}
	data->tex_x = (int)(ray->wall_x * data->tex_size);
	if (ray->side == 0 && ray->dir_x > 0)
		data->tex_x = data->tile_w - data->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		data->tex_x = data->tile_w - data->tex_x - 1;
}

void	update_texture_pixels(t_data *data, t_ray *ray, int x)
{
	set_texture_x_coord(data, ray);
	calc_x_coord_pl_facing_left_up(data, ray);
	handle_vert_wall_px(data, ray, x);
}

int	check_map_boundaries(t_data *data, t_ray *ray)
{
	return (ray->map_y < 0.25 || ray->map_x < 0.25
		|| ray->map_y > data->map_height - 0.25
		|| ray->map_x > data->map_width - 1.25);
}

void	calc_px_filler(t_ray *ray, t_data *data)
{
	ray->draw_start = -(ray->line_height) / 2 + data->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2;
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
}

void	calc_line_height(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->line_height = (int)(data->win_height / ray->perp_wall_dist);
}
