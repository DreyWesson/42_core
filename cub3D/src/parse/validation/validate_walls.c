/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:13:41 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 12:13:30 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	flood_fill(char **tab, t_point size, int x, int y)
{
	int	result;

	if (y < 0 || y >= size.y || x < 0 || x >= size.x)
		return (FAILURE);
	if (tab[y][x] == 'v' || tab[y][x] == '1')
		return (1);
	tab[y][x] = 'v';
	result = flood_fill(tab, size, x, y + 1);
	if (result != FAILURE)
		result = flood_fill(tab, size, x, y - 1);
	if (result != FAILURE)
		result = flood_fill(tab, size, x - 1, y);
	if (result != FAILURE)
		result = flood_fill(tab, size, x + 1, y);
	return (result);
}

int	validate_walls(t_data *data)
{
	return (flood_fill(data->map, (t_point){data->map_width, data->map_height},
		data->player.x, data->player.y));
}
