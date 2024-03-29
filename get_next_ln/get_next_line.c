/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 07:59:31 by doduwole          #+#    #+#             */
/*   Updated: 2023/06/20 16:33:17 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char	**str)
{
	if (str[0])
	{
		free(str[0]);
		str[0] = NULL;
	}
}

void	ft_concat_chunks(char	**line, char	**chunk)
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

char	*ft_split(char	**str)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[j] = s2[i];
		j++;
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*chunk;
	int			size;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	chunk = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	size = read(fd, chunk, BUFFER_SIZE);
	if (size == -1 || !chunk)
	{
		ft_free(&chunk);
		ft_free(&line);
	}
	while (size > 0)
	{
		chunk[size] = '\0';
		ft_concat_chunks(&line, &chunk);
		if (ft_strchr(line, '\n'))
			break ;
		size = read(fd, chunk, BUFFER_SIZE);
	}
	return (ft_free(&chunk), ft_split(&line));
}

// int main()
// {
//     char buf[3][10] = {"text1", "text2", "test3"};
//     int fd;
//     int i;
//     int j = -1;
//     char *line;
//     while (++j < 3)
//     {
//         i = -1;
//         fd = open(buf[j],O_RDONLY);
//         while (++i < 8)
//         {
//             line = get_next_line(fd);
//             printf("%s", line);
//             free(line);
//         }
//         printf("\n");
//         close(fd);
//     }
//     return (0);
// }