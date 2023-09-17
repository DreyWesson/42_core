/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 02:25:36 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/30 17:29:47 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	south_wall_error(t_wall_img wall)
{
	if (!wall.south_east)
		printf("south_east.xpm file not opening\n");
	if (!wall.south)
		printf("south_wall.xpm file not opening\n");
	if (!wall.south_west)
		printf("south_west.xpm file not opening\n");
	if (!wall.south_east || !wall.south || !wall.south_west)
		return (0);
	return (1);
}

int	north_wall_error(t_wall_img wall)
{
	if (!wall.block)
		printf("wall.xpm file not opening\n");
	if (!wall.north_west)
		printf("north_west.xpm file not opening\n");
	if (!wall.north)
		printf("north.xpm file not opening\n");
	if (!wall.north_east)
		printf("north_east.xpm file not opening\n");
	if (!wall.block || !wall.north_west || !wall.north || !wall.north_east)
		return (0);
	return (1);
}

int	east_wall_error(t_wall_img wall)
{
	if (!wall.east)
	{
		printf("east_wall.xpm file not opening\n");
		return (0);
	}
	return (1);
}

int	west_wall_error(t_wall_img wall)
{
	if (!wall.west)
	{
		printf("west_wall.xpm file not opening\n");
		return (0);
	}
	return (1);
}
