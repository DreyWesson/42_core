/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:04:47 by ioduwole          #+#    #+#             */
/*   Updated: 2023/01/24 23:02:26 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mark_path(t_data *game, int row, int col, int **marked)
{
	if ((row < 0 || row >= game->row) && (col < 0 || col >= game->col))
		return ;
	if (game->map[row][col] != '1' && marked[row][col] != 1)
	{
		marked[row][col] = 1;
		mark_path(game, row, col + 1, marked);
		mark_path(game, row, col - 1, marked);
		mark_path(game, row + 1, col, marked);
		mark_path(game, row - 1, col, marked);
	}
}

int	check_path(t_data *game, int **marked)
{
	int	exit;
	int	potions;
	int	col;
	int	row;

	exit = 0;
	potions = 0;
	row = -1;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
			if ((game->map[row][col] == 'E') && (marked[row][col]))
				exit++;
			if ((game->map[row][col] == 'C') && (marked[row][col]))
				potions++;
		}
	}
	if ((exit + potions) == (game->potions + 1))
		return (1);
	return (ft_printf("Error: check map paths to Collectibles and Exit\n"), 0);
}

int	is_path(t_data *game)
{
	int		**marked;
	int		valid;
	int		i;

	i = 0;
	valid = 1;
	marked = (int **)ft_calloc(game->row, sizeof(int *));
	while (i < game->row)
	{
		marked[i] = (int *)ft_calloc(game->col, sizeof(int));
		i++;
	}
	mark_path(game, game->player[0], game->player[1], marked);
	valid = check_path(game, marked);
	while (--i >= 0)
		free(marked[i]);
	free(marked);
	return (valid);
}
