/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:46:59 by loandrad          #+#    #+#             */
/*   Updated: 2023/11/11 22:59:25 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	init_texture_pixels(t_data *data)
{
	int	i;

	i = 0;
	if (data->tex_pixels)
		free_array_2d((void **)data->tex_pixels);
	data->tex_pixels = ft_calloc(data->win_height + 1,
			sizeof * data->tex_pixels);
	if (!data->tex_pixels)
		clean_exit(data, FAILURE);
	while (i < data->win_height)
	{
		data->tex_pixels[i] = ft_calloc(data->win_width + 1,
				sizeof * data->tex_pixels);
		if (!data->tex_pixels[i])
			clean_exit(data, FAILURE);
		i++;
	}
}

void	render_images(t_data *data)
{
	init_texture_pixels(data);
	ft_memset((void *)&data->ray, 0, sizeof(data->ray));
	ray_casting(data);
	render_frame(data);
}
