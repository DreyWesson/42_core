/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:58:08 by loandrad          #+#    #+#             */
/*   Updated: 2023/11/12 00:49:34 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	init_img(t_data *data, t_img *image, int width, int height)
{
	ft_memset((void *)image, 0, sizeof(*image));
	image->img = mlx_new_image(data->mlx_ptr, width, height);
	if (image->img == NULL)
		clean_exit(data, FAILURE);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}

static void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / FOUR_BYTE) + x;
	image->addr[pixel] = color;
}

static void	set_colors_and_textures(t_data *data, t_img *image, int x, int y)
{
	if (data->tex_pixels[y][x] > 0)
		set_image_pixel(image, x, y, data->tex_pixels[y][x]);
	else if (y < data->win_height / 2)
		set_image_pixel(image, x, y, data->col_ceiling_int);
	else if (y < data->win_height - 1)
		set_image_pixel(image, x, y, data->col_floor_int);
}

void	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(data, &image, data->win_width, data->win_height);
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_colors_and_textures(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, image.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, image.img);
}
