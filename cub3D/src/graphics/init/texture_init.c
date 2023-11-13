/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 00:59:34 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 12:46:01 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	init_texture_img(t_data *data, t_img *image_details, char *path)
{
	ft_memset((void *)image_details, 0, sizeof(*image_details));
	image_details->img = mlx_xpm_file_to_image(data->mlx_ptr,
			path, &data->tile_w, &data->tile_h);
	if (image_details->img == NULL)
	{
		ft_error("Malloc failed!");
		clean_exit(data, FAILURE);
	}
	image_details->addr = (int *)mlx_get_data_addr(image_details->img,
			&image_details->pixel_bits, &image_details->size_line,
			&image_details->endian);
}

static int	*xpm_to_img(t_data *data, char *tex_path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	y = 0;
	init_texture_img(data, &tmp, tex_path);
	buffer = ft_calloc(sizeof(*buffer), data->tile_h * data->tile_w);
	if (!buffer)
		clean_exit(data, FAILURE);
	while (y < data->tile_h)
	{
		x = 0;
		while (x < data->tile_w)
		{
			buffer[y * data->tile_w + x]
				= tmp.addr[y * data->tile_w + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx_ptr, tmp.img);
	return (buffer);
}

void	texture_init(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
		clean_exit(data, FAILURE);
	data->textures[NORTH] = xpm_to_img(data, data->north_tex);
	data->textures[SOUTH] = xpm_to_img(data, data->south_tex);
	data->textures[EAST] = xpm_to_img(data, data->east_tex);
	data->textures[WEST] = xpm_to_img(data, data->west_tex);
}
