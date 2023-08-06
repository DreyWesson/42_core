/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 01:36:59 by ioduwole          #+#    #+#             */
/*   Updated: 2023/01/26 12:28:32 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(t_data *game, char *argv[])
{
	int		fd;
	char	*tmp;
	int		i;

	i = 0;
	game->map = ft_calloc(game->row + 1, sizeof(char *));
	if (!game->map)
		return (ft_printf("Memory allocation failed\n"), 0);
	fd = open(argv[1], O_RDONLY);
	game->map[game->row] = NULL;
	tmp = get_next_line(fd);
	game->map[0] = ft_strtrim(tmp, "\n");
	free(tmp);
	while (game->map[i])
	{
		tmp = get_next_line(fd);
		game->map[++i] = ft_strtrim(tmp, "\n");
		free(tmp);
	}
	close(fd);
	game->col = ft_strlen(game->map[0]);
	if (search_map(game) != 1 || game->exit != 1 || game->potions < 1)
		return (ft_printf("Error: Check that P == 1, E == 1. C > 0\n"), 0);
	return (1);
}

int	search_map(t_data *game)
{
	int		i;
	int		j;
	int		p;

	i = -1;
	p = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				p++;
				game->player[0] = i;
				game->player[1] = j;
			}
			else if (game->map[i][j] == 'E')
				game->exit += 1;
			else if (game->map[i][j] == 'C')
				game->potions += 1;
		}
	}
	return (p);
}

void	init_data(t_data *game)
{
	game->row = 0;
	game->col = 0;
	game->potions = 0;
	game->exit = 0;
	game->steps = 0;
	game->collected = 0;
}
