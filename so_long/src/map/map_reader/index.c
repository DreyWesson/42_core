/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 07:45:52 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/12 16:43:35 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

// int	line_counter(char *file_name)
// {
// 	int	i;
// 	int	fd;

// 	i = 0;
// 	fd = open(file_name, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_error("Some error occurred");
// 		exit(1);
// 	}
// 	while (get_next_line(fd))
// 		i++;
// 	return (i);
// }

// size_t	ft_strlen_ln(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0' && str[i] != '\n')
// 		i++;
// 	return (i);
// }

char	**map_reader(char *s, int line_nbr)
{
	char	**ptr;
	char	*str;
	int		i;
	int		len;
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Some error occurred");
		exit(1);
	}
	// line_nbr = line_counter(s);
	ptr = (char **)ft_calloc(sizeof(char *), line_nbr + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < line_nbr)
	{
		str = get_next_line(fd);
		len = ft_strlen_ln(str);
		ptr[i] = ft_substr(str, 0, len);
		ptr[i][len] = '\0';
		i++;
	}
	return (ptr);
}
