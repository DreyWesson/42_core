/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:43:00 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/29 22:51:25 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	draw_player(t_game game, t_axis pos)
{
	mlx_put_image_to_window(game.mlx, game.window,
		game.player.current_img, pos.x, pos.y);
}
