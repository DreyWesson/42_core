/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:51:10 by loandrad          #+#    #+#             */
/*   Updated: 2023/11/12 01:20:46 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	texturing_calc(t_ray *ray, t_data *data)
{
	if (ray->side == 0)
		ray->wall_x = data->player.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = data->player.pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

static void	perform_dda(t_data *data, t_ray *ray)
{
	int	hit_wall;

	hit_wall = 0;
	while (hit_wall == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (check_map_boundaries(data, ray))
			break ;
		else if (data->map[ray->map_y][ray->map_x] > '0')
			hit_wall = 1;
	}
}

static void	calc_step_and_init_side_dist(t_ray *ray, t_data *data)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x
			= (ray->map_x + 1.0 - data->player.pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y
			= (ray->map_y + 1.0 - data->player.pos_y) * ray->delta_dist_y;
	}
}

static void	init_ray_casting(int x, t_ray *ray, t_data *data)
{
	ft_memset((void *)&data->ray, 0, sizeof(data->ray));
	ray->camera_x = 2 * x / (double)data->win_width - 1;
	ray->dir_x = data->player.dir_x + data->player.plane_x * ray->camera_x;
	ray->dir_y = data->player.dir_y + data->player.plane_y * ray->camera_x;
	ray->map_x = (int)data->player.pos_x;
	ray->map_y = (int)data->player.pos_y;
	ray->delta_dist_x = fabs(1 / ray->dir_x);
	ray->delta_dist_y = fabs(1 / ray->dir_y);
}

int	ray_casting(t_data *data)
{
	t_ray	*ray;
	int		x;

	x = 0;
	ray = &data->ray;
	while (x < data->win_width)
	{
		init_ray_casting(x, ray, data);
		calc_step_and_init_side_dist(ray, data);
		perform_dda(data, ray);
		calc_line_height(ray, data);
		calc_px_filler(ray, data);
		texturing_calc(ray, data);
		update_texture_pixels(data, ray, x);
		x++;
	}
	return (SUCCESS);
}
