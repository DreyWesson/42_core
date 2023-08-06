/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:03:41 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/06 07:11:31 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*validate_map(int argc, char *argv[])
{
	t_data	*game;
	char	*tmp;
	int		fd;

	if (argc != 2)
		return (ft_printf("Error: Wrong argument.\n"), NULL);
	tmp = ft_strchr(argv[1], '.');
	if (!tmp || ft_strncmp(tmp, ".ber", 4) || ft_strlen(tmp) != 4)
		return (ft_printf("Error: Check map name.\n"), NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: Unable to open the map.\n"), NULL);
	game = (t_data *)ft_calloc(1, sizeof(t_data));
	init_data(game);
	if (!(checker(game, fd)))
		return (free(game), close(fd), NULL);
	close(fd);
	if (!get_map(game, argv) || !is_path(game))
		return (clear_game(game), NULL);
	return (game);
}

int	fline(char *tmp, int flag)
{
	int			i;
	static int	len;

	i = 0;
	if (len - 1 != (int)ft_strlen(tmp) && flag == 2)
		return (0);
	len = ft_strlen(tmp);
	if (tmp[len - 1] != '\n' && flag == 1)
		return (free(tmp), ft_printf("Error: Invalid Map.\n"), 0);
	while (tmp[i])
	{	
		if (!(tmp[i] == '1' || tmp[i] == '\n'))
			return (free(tmp), ft_printf("Error: Invalid Map.\n"), 0);
		i++;
	}
	free(tmp);
	return (i);
}

int	mid_lines(char *tmp, int len)
{
	int	i;

	i = ft_strlen(tmp);
	if (tmp[0] != '1' || tmp[i - 2] != '1' || i != len)
		return (free(tmp), ft_printf("Error: Invalid Map.\n"), 0);
	i -= 2;
	while (i >= 0)
	{
		if (!(tmp[i] == '1' || tmp[i] == 'E' || tmp[i] == '0'
				|| tmp[i] == 'P' || tmp[i] == 'C'))
			return (free(tmp), ft_printf("Error: Invalid Map.\n"), 0);
		i--;
	}
	free(tmp);
	return (ft_strlen(tmp));
}

int	checker(t_data *game, int fd)
{
	char	*tmp;
	char	*next;

	tmp = get_next_line(fd);
	game->col = fline(tmp, 1);
	if (game->col == 0)
		return (0);
	tmp = get_next_line(fd);
	next = get_next_line(fd);
	game->row = 2;
	while (next)
	{
		if (!mid_lines(tmp, game->col))
			return (free(next), 0);
		tmp = next;
		next = get_next_line(fd);
		game->row++;
	}
	if (!fline(tmp, 2))
		return (ft_printf("Error: Invalid Map.\n"), 0);
	if (game->row == game->col - 1 || game->row < 3 || game->col < 4)
		return (ft_printf("Error: Invalid Map.\n"), 0);
	if ((game->row == 3 && game->col < 6) || (game->col == 4 && game->row < 5))
		return (ft_printf("Error\n"), 0);
	return (1);
}

void	clear_game(t_data *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free (game->map[i]);
			i++;
		}
		free(game->map);
	}
	free(game);
}
