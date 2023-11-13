/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:04:20 by doduwole          #+#    #+#             */
/*   Updated: 2023/10/10 22:05:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_error("File error");
		exit(1);
	}
}

int	line_counter(char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

size_t	ft_strlen_ln(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen_no_newline(const char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			len++;
		i++;
	}
	return (len);
}

size_t	find_max_width(t_data *data, int i)
{
	size_t	max_width;

	max_width = ft_strlen_no_newline(data->cub_file[i]);
	while (data->cub_file[i])
	{
		if (ft_strlen_no_newline(data->cub_file[i]) > max_width)
			max_width = ft_strlen_no_newline(data->cub_file[i]);
		i++;
	}
	return (max_width);
}
