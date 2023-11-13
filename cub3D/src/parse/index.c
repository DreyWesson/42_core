/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:15:02 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 12:49:16 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	parsing(t_data *data, char **argv)
{
	init_data(data);
	handle_cub(argv[1], data);
	if (retrieve_file_data(data, data->cub_file) == FAILURE)
		return (FAILURE);
	if (validate_map(data, data->map) == FAILURE)
		return (FAILURE);
	if (validate_textures(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
