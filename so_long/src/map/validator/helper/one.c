/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:29:43 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/12 16:56:37 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/so_long.h"

void	validate_composition(char s, t_qty *qty)
{
	char	*set;

	set = "01CEP";
	if (!ft_strchr(set, s))
	{
		ft_error("Invalid composition");
		exit(0);
	}
	else
	{
		if (s == 'C')
			(*qty).c += 1;
		else if (s == 'E')
			(*qty).e += 1;
		else if (s == 'P')
			(*qty).p += 1;
	}
}

void validate_walls(char *s, int line_nbr, int j, int i)
{
	if (s[j] != '1' && (i == 0 || i == line_nbr - 1
			|| j == 0 || s[j + 1] == '\0'))
	{
		ft_error("Should be surrounded by walls");
		exit(0);
	}
}

void	validate_shape(int line_nbr, int *col_nbr, int i, int j)
{
	if (i == 0)
		*col_nbr = j;
	if (j == line_nbr || *col_nbr != j)
	{
		ft_error("Provide rectangular maps only");
		exit(0);
	}
}

t_coord	save_start(int x, int y)
{
	t_coord	start_pos;

	start_pos.x = x;
	start_pos.y = y;
	return (start_pos);
}

void	check_quant(t_qty *qty)
{
	if (qty->c < 1 || qty->e != 1 || qty->p != 1)
	{
		ft_error("Invalid composition quantity");
		exit(0);
	}
	free(qty);
}
