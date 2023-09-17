/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:05:13 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/30 17:22:41 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_error(char *message)
{
	ft_printf("\033[1;31m" "Error\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
	return (0);
}

void	ft_warning(char *message)
{
	ft_printf("\033[1;33m" "Warning\n" "\033[0m");
	ft_printf("\033[3m\033[2;37m" " %s\n" "\033[0m", message);
}

int	door_imgs_error(t_game game)
{
	if (!game.door_close_img)
		printf("door_open.xpm file not opening\n");
	if (!game.door_open_img)
		printf("door_close.xpm file not opening\n");
	if (!game.door_close_img || !game.door_open_img)
	{
		free_grid(game.grid, game.props.row_nbr, 1);
		return (0);
	}
	return (1);
}

int	collectible_imgs_error(t_game game)
{
	if (!game.collects_imgs.img_0)
		printf("plant_01.xpm file not opening\n");
	if (!game.collects_imgs.img_1)
		printf("plant_02.xpm file not opening\n");
	if (!game.effect.img)
		printf("jump_plant.xpm file not opening\n");
	if (!game.collects_imgs.img_0 || !game.collects_imgs.img_1
		|| !game.effect.img)
	{
		free_grid(game.grid, game.props.row_nbr, 1);
		return (0);
	}
	return (1);
}

int	player_imgs_error(t_game game)
{
	if (!game.player.idle_img_0)
		printf("player_01.xpm file not opening\n");
	if (!game.player.idle_img_1)
		printf("player_02.xpm file not opening\n");
	if (!game.player.action_img)
		printf("player_03.xpm file not opening\n");
	if (!game.player.idle_img_0 || !game.player.idle_img_1
		|| !game.player.action_img)
	{
		free_grid(game.grid, game.props.row_nbr, 1);
		return (0);
	}
	return (1);
}
