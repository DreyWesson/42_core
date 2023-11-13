/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:07:25 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 12:07:45 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

static int	open_file(char *filepath, t_data *data)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_error("File failed to open");
		clean_exit(data, FAILURE);
	}
	return (fd);
}

static void	init_map(char *cub_path, t_data *data)
{
	data->cub_height = line_counter(cub_path);
	data->cub_file = ft_calloc(sizeof(char *), data->cub_height + 1);
	data->cub_path = cub_path;
	if (!data->cub_file)
		return (ft_err("Malloc failed"), clean_exit(data, FAILURE));
	data->cub_fd = open_file(cub_path, data);
}

static void	map_reader(t_data *data)
{
	char	*line;
	int		row;
	int		col;
	int		i;

	i = 0;
	row = 0;
	col = 0;
	line = get_next_line(data->cub_fd);
	while (line != NULL)
	{
		data->cub_file[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->cub_file[row])
			return (ft_error("Malloc failed"), clean_exit(data, FAILURE));
		while (line[i] != '\0')
			data->cub_file[row][col++] = line[i++];
		data->cub_file[row++][col] = '\0';
		col = 0;
		i = 0;
		free(line);
		line = get_next_line(data->cub_fd);
	}
	data->cub_file[row] = NULL;
	close(data->cub_fd);
}

void	handle_cub(char *cub_path, t_data *data)
{
	if (!is_valid_exe(cub_path, ".cub"))
	{
		ft_error("Expecting a .cub file");
		exit(1);
	}
	init_map(cub_path, data);
	map_reader(data);
}
