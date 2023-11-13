/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:22:39 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 14:32:51 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static int	handle_extraction(t_data *data, char **cub_file, int i, int j)
{
	while (ft_isspace(cub_file[i][j]) || cub_file[i][j] == '\n')
		j++;
	if (is_texture_or_color(cub_file[i][j]))
	{
		if (is_texture(cub_file[i][j], cub_file[i][j + 1]))
		{
			if (add_textures(data, cub_file[i], j) == FAILURE)
				return (FAILURE);
		}
		else
		{
			if (add_colors(data, cub_file[i], j) == FAILURE)
				return (FAILURE);
		}
		return (TEXTURE_ADDED);
	}
	else if (ft_isdigit(cub_file[i][j]))
	{
		if (add_map(data, cub_file, i) == FAILURE)
			return (FAILURE);
		return (SUCCESS);
	}
	return (42);
}

int	retrieve_file_data(t_data *data, char **cub_file)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	while (cub_file[i])
	{
		j = 0;
		while (cub_file[i][j])
		{
			status = handle_extraction(data, cub_file, i, j);
			if (status == FAILURE)
				return (FAILURE);
			else if (status == SUCCESS)
				return (SUCCESS);
			else if (status == TEXTURE_ADDED)
				break ;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
