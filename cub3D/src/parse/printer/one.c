/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:08:40 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 12:53:20 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	ft_error(char *message)
{
	ft_printf("\033[1;31m""Error\n""\033[0m");
	ft_printf("\033[3m\033[2;37m"" %s\n""\033[0m", message);
	return (0);
}

void	ft_err(char *message)
{
	ft_printf("\033[1;31m""Error\n""\033[0m");
	ft_printf("\033[3m\033[2;37m"" %s\n""\033[0m", message);
}

void	print_grid(char **map, int row_nbr)
{
	int	y;

	y = 0;
	while (y < row_nbr)
	{
		printf("%s\n", map[y]);
		y++;
	}
}

void	print_array_2d(char **array_2d)
{
	int	i;

	i = 0;
	while (array_2d[i])
	{
		printf("%s", array_2d[i]);
		i++;
	}
}

void	print_array_2d_newline(char **array_2d)
{
	int	i;

	i = 0;
	while (array_2d[i])
	{
		printf("%s", array_2d[i]);
		printf("\n");
		i++;
	}
}
