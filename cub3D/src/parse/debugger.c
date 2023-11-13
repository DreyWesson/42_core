/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:07:59 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/09 12:48:53 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	texture_data(t_data *data)
{
	printf("\033[1;33m""Saved textures:\n""\033[0m");
	printf("South: %s\n", data->south_tex);
	printf("North: %s\n", data->north_tex);
	printf("West: %s\n", data->west_tex);
	printf("East: %s\n", data->east_tex);
	printf("\n");
}

void	player_data(t_data *data)
{
	printf("\033[1;33m""Player data:\n""\033[0m");
	printf("player_dir: %c\n",
		data->player.dir);
	printf("player_x: %i\n", data->player.x);
	printf("player_y: %i\n", data->player.y);
	printf("\n");
}

void	color_data(int *data, char *str)
{
	int	i;

	i = 0;
	printf("\033[1;33m""%s color data:\n""\033[0m", str);
	while (i < 3)
	{
		printf("%d", data[i]);
		if (i != 2)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	debugger(t_data *data)
{
	texture_data(data);
	color_data(data->col_ceiling, "Ceiling");
	color_data(data->col_floor, "Floor");
	print_map(data, "Rectangular map");
	player_data(data);
}
