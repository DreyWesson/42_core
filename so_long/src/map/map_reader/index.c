/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 07:45:52 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/31 23:10:30 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	check_fd(int fd)
{
	if (fd < 0)
	{
		ft_error("Some error occurred");
		exit(1);
	}
}

char	**map_reader(char *s, int row_nbr)
{
	char	**ptr;
	char	*str;
	int		i;
	int		len;
	int		fd;

	fd = open(s, O_RDONLY);
	check_fd(fd);
	ptr = (char **)ft_calloc(sizeof(char *), row_nbr + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < row_nbr)
	{
		str = get_next_line(fd);
		len = ft_strlen_ln(str);
		ptr[i] = ft_substr(str, 0, len);
		ptr[i][len] = '\0';
		i++;
		free(str);
	}
	return (ptr);
}
