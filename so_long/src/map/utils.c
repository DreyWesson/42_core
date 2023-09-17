/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:25:55 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/31 23:08:09 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	check_len(int len)
{
	if (len == 4)
	{
		ft_error("File name doesn't exist");
		exit(0);
	}
}

int	is_valid(char *str)
{
	char	*s;
	int		len;
	int		res;

	res = 0;
	s = NULL;
	len = ft_trim(str, "./");
	while (str[len])
	{
		if (str[len] == '.')
		{
			s = ft_substr(&str[len], 0, 4);
			if (ft_strncmp(s, ".ber", 4) == 0 && !str[len + 4])
				res = 1;
			else
				break ;
		}
		len++;
	}
	check_len(len);
	free(s);
	return (res);
}

int	count_collected(t_nodes **queue)
{
	char	c;

	c = (*queue)->cell->val;
	if (c != SPACE && c != BLOCK && c != PLAYER)
		return (1);
	return (0);
}

int	check_paths(t_cell **grid, t_nodes **queue, t_details details)
{
	int	memo;

	if (grid[details.pos.y][details.pos.x].val == 'P')
		add_head_node(queue, create_node(&grid[details.pos.y][details.pos.x]));
	handle_adjacency(grid, queue);
	memo = count_collected(queue);
	del_node(queue);
	if (!*queue)
		return (memo);
	details.pos.x = (*queue)->cell->x_axis;
	details.pos.y = (*queue)->cell->y_axis;
	return (check_paths(grid, queue, details) + memo);
}

t_cell	**validate_paths(t_cell **grid, t_nodes **queue,
	t_details details, char **map)
{
	int		collectibles;
	int		collected;
	int		collected_tmp;
	t_cell	**cache;

	collectibles = special_char(map);
	cache = create_grid(map, &details);
	cache[details.cache_exit.y][details.cache_exit.x].val = '1';
	collected_tmp = check_paths(cache, queue, details);
	collected = check_paths(grid, queue, details);
	if ((collected_tmp + 1) != collectibles || collected != collectibles)
	{
		ft_error("Invalid path(s)");
		ft_free2d(map);
		alt_free_grid(grid, details.row_nbr);
		alt_free_grid(cache, details.row_nbr);
		exit(1);
	}
	alt_free_grid(cache, details.row_nbr);
	return (grid);
}
