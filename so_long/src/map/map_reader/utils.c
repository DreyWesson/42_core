/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:43:12 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/12 16:43:44 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

int	line_counter(char *file_name)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Some error occurred");
		exit(1);
	}
	while (get_next_line(fd))
		i++;
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