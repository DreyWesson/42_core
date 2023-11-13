/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:00:58 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/11 22:22:10 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

int	game_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_error("MLX failed to initialize!"), FAILURE);
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			data->win_width, data->win_height, "Cub3D");
	if (!data->mlx_win)
		return (ft_error("MLX failed to initialize!"), FAILURE);
	return (SUCCESS);
}
