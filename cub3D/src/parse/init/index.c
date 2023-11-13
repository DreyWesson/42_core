/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:30:39 by eramusho          #+#    #+#             */
/*   Updated: 2023/11/08 13:58:49 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	init_data(t_data *data)
{
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	data->cub_fd = -42;
	data->tile_w = TILE_W;
	data->tile_h = TILE_H;
	data->tex_size = TILE_W;
}
