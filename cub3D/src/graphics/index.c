/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:39:39 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 12:39:30 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	end_program(t_data *data)
{
	clean_exit(data, 0);
	return (0);
}

int	build_graphics(t_data *data)
{
	handle_compass(data);
	game_init(data);
	texture_init(data);
	render_images(data);
	return (1);
}
