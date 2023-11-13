/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:35:16 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 12:12:30 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static void	fill_up_gaps(char *new_line, t_data *data, int line_num)
{
	int	i;
	int	line_width;

	i = 0;
	line_width = ft_strlen(data->map[line_num]);
	while (i < line_width)
	{
		if (data->map[line_num][i] == ' ')
			new_line[i] = '0';
		else
			new_line[i] = data->map[line_num][i];
		i++;
	}
	while (i < data->map_width)
	{
		new_line[i] = '0';
		i++;
	}
	new_line[i] = '\0';
}

void	make_map_rectangular(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	while (i < data->map_height)
	{
		line = (char *)ft_calloc(sizeof(char), (data->map_width + 1));
		if (!line)
		{
			ft_error("Malloc failed");
			return ;
		}
		fill_up_gaps(line, data, i);
		free(data->map[i]);
		data->map[i] = line;
		i++;
	}
}
