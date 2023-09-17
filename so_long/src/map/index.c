/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:27:09 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/31 23:16:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	handle_map(char **argv, t_game *game)
{
	char		**ptr;
	t_details	props;
	t_nodes		*queue;
	t_cell		**grid;

	queue = NULL;
	grid = NULL;
	props = default_details(argv[1]);
	ptr = map_reader(argv[1], props.row_nbr);
	grid = validate_map(ptr, &props, &queue);
	ft_free2d(ptr);
	if (!grid || !build_graphics(game, grid, props))
		return (free_grid(grid, props.row_nbr, 1), 0);
	return (1);
}

int	validate_arg(int argc, char **argv)
{
	if (argc == 1)
		return (ft_error("Too few argument"));
	if (argc > 2)
		return (ft_error("Too many argument"));
	if (!is_valid(argv[1]))
		return (ft_error("Expecting a .ber file"));
	return (1);
}

int	handle_validation(int argc, char **argv, t_game *game)
{
	if (!validate_arg(argc, argv))
		return (0);
	if (!handle_map(argv, game))
	{
		if (game->grid)
			free_grid(game->grid, game->props.row_nbr, 1);
		return (0);
	}
	return (1);
}
