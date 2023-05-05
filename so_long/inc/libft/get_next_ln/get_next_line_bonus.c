/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:04:49 by doduwole          #+#    #+#             */
/*   Updated: 2023/04/24 23:50:22 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	void	ft_free(char **str)
{
	if (str[0])
	{
		free(str[0]);
		str[0] = NULL;
	}
}

void	ft_concat_chunks(char **line, char **chunk)
{
	char	*tmp;

	if (!(*line))
		*line = ft_strdup(*chunk);
	else
	{
		tmp = ft_strjoin(*line, *chunk);
		ft_free(line);
		*line = tmp;
	}
}

char	*ft_splitln(char **str)
{
	char	*line;
	char	*excess_bytes;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[0][i] != '\n' && str[0][i] != '\0')
		i++;
	line = ft_substr(str[0], 0, i + 1);
	excess_bytes = ft_substr(str[0], i + 1, ft_strlen(str[0]));
	ft_free(str);
	str[0] = ft_strdup(excess_bytes);
	ft_free(&excess_bytes);
	if (!ft_strchr(line, '\n'))
	{
		if (!ft_strlen(line))
			ft_free(&line);
		ft_free(str);
	}
	return (line);
}

char	*get_next_line_bn(int fd)
{
	static char	*line[BUFFER_SIZE];
	char		*chunk;
	int			size;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	size = read(fd, chunk, BUFFER_SIZE);
	if (size == -1 || !chunk)
	{
		ft_free(&chunk);
		ft_free(&line[fd]);
	}
	while (size > 0)
	{
		chunk[size] = '\0';
		ft_concat_chunks(&line[fd], &chunk);
		if (ft_strchr(line[fd], '\n'))
			break ;
		size = read(fd, chunk, BUFFER_SIZE);
	}
	return (ft_free(&chunk), ft_splitln(&line[fd]));
}
