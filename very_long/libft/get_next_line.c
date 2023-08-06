/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:05:29 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/11 10:57:17 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_line(char *finder)
{
	char	*found;

found = ft_strchr(finder, '\n');
	if (!found)
	{
		free(finder);
		return (0);
	}
	if (*(found + 1))
	found = ft_strdup(found + 1);
	else
		found = NULL;
	free (finder);
	return (found);
}

char	*get_next_line(int fd)
{
	static char		*tstring;
	char			*dest;
	char			line[BUFFER_SIZE + 1];
	int				size;

	size = read(fd, line, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	line[size] = '\0';
	while (size > 0)
	{
		if (!tstring)
			tstring = ft_strdup(line);
		else
			tstring = ft_strjoin(tstring, line);
		if (ft_strchr(line, '\n'))
			break ;
		size = read(fd, line, BUFFER_SIZE);
		line[size] = '\0';
	}
	dest = ft_substr(tstring, 0, ft_strchr(tstring, '\n')
			- tstring + 1);
	tstring = find_line(tstring);
	return (dest);
}

// int main(void)
// {
// 	int fd;
// 	fd = open("b.txt", O_RDONLY);
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd));
// 		printf("%s", get_next_line(fd));
// }