/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:29:43 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/31 22:56:21 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/so_long.h"

int	validate_composition(char s, t_quant *quant)
{
	char	*set;

	set = "01CEP";
	if (!ft_strchr(set, s))
	{
		ft_error("Invalid composition");
		return (0);
	}
	else
	{
		if (s == 'C')
			(*quant).collectibles += 1;
		else if (s == 'E')
			(*quant).exit += 1;
		else if (s == 'P')
			(*quant).player += 1;
	}
	return (1);
}

int	validate_walls(char *s, int row_nbr, int j, int i)
{
	if (s[j] != '1' && (i == 0 || i == row_nbr - 1
			|| j == 0 || s[j + 1] == '\0'))
	{
		ft_error("Should be surrounded by walls");
		return (0);
	}
	return (1);
}

int	validate_shape(t_details *details, int i, int j)
{
	if (i == 0)
		details->col_nbr = j;
	if (j == details->row_nbr || (*details).col_nbr != j)
	{
		ft_error("Provide rectangular maps only");
		return (0);
	}
	return (1);
}

void	save_start(int y, int x, t_details *details)
{
	details->pos.y = y;
	details->pos.x = x;
}

void	check_quant(char **map, t_quant *quant, t_details *details)
{
	if (quant->collectibles < 1 || quant->exit != 1 || quant->player != 1)
	{
		ft_error("Invalid composition quantity");
		ft_free2d(map);
		exit(0);
	}
	details->burger_nbr = quant->collectibles;
}
