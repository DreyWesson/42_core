/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:25:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 14:49:57 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static unsigned long	rgb_to_int(int *rgb_arr)
{
	int	r;
	int	g;
	int	b;

	r = rgb_arr[0];
	g = rgb_arr[1];
	b = rgb_arr[2];
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

static int	validate_xpm_file(char *filename)
{
	int	fd;

	if (!is_valid_exe(filename, ".xpm"))
		return (ft_error("Expecting a .xpm file"), FAILURE);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_error("Couldn't open file"), FAILURE);
	close(fd);
	return (SUCCESS);
}

static int	handle_xpm(t_data *data)
{
	return (
		validate_xpm_file(data->north_tex) == FAILURE
		|| validate_xpm_file(data->east_tex) == FAILURE
		|| validate_xpm_file(data->west_tex) == FAILURE
		|| validate_xpm_file(data->south_tex) == FAILURE
	);
}

int	validate_textures(t_data *data)
{
	if (!data->north_tex || !data->east_tex || !data->west_tex
		|| !data->south_tex)
		return (ft_error("Textures: Missing data"), FAILURE);
	if (!data->col_floor || !data->col_ceiling)
		return (ft_error("Color: Missing"), FAILURE);
	if (handle_xpm(data))
		return (FAILURE);
	data->col_ceiling_int = rgb_to_int(data->col_ceiling);
	data->col_floor_int = rgb_to_int(data->col_floor);
	return (SUCCESS);
}
