/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:19:03 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 14:31:46 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static int	check_map_is_at_the_end(t_data *data)
{
	int	i;
	int	j;

	i = data->map_end_idx;
	while (data->cub_file[i])
	{
		j = 0;
		while (data->cub_file[i][j])
		{
			if (!ft_isspace(data->cub_file[i][j])
				&& data->cub_file[i][j] != '\n')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	add_player_position(t_data *data, char **map)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (ft_error("Map: no player found"), FAILURE);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NEWS", map[i][j]))
			{
				data->player.x = j;
				data->player.y = i;
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_map_elements(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			while (ft_isspace(data->map[i][j]))
				j++;
			if (!(ft_strchr("10NEWS", map[i][j])))
				return (ft_error("Map: Invalid map"), FAILURE);
			if (ft_strchr("NEWS", map[i][j]) && data->player.dir != '0')
				return (ft_error("Map: Invalid map"), FAILURE);
			if (ft_strchr("NEWS", map[i][j]) && data->player.dir == '0')
				data->player.dir = map[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static void	set_map_to_default(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (data->map[i][j] == 'v')
				data->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	validate_map(t_data *data, char **map)
{
	if (!data->map)
		return (ft_error("Map: no map found"), FAILURE);
	if (check_map_elements(data, map) == FAILURE)
		return (FAILURE);
	if (add_player_position(data, map) == FAILURE)
		return (FAILURE);
	if (check_map_is_at_the_end(data) == FAILURE)
		return (ft_error("Map: Should be the last element in file"), FAILURE);
	make_map_rectangular(data);
	if (validate_walls(data) == FAILURE)
		return (ft_error("Map: Should be surrounded by walls"), FAILURE);
	set_map_to_default(data);
	return (SUCCESS);
}
