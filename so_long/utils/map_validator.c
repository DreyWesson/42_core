/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:29:43 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/29 12:32:51 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
		if ((*qty).c > 1 || (*qty).e > 1 || (*qty).p > 1)
		{
			ft_error("Invalid composition quantity");
			exit(0);
		}
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
	if (j <= line_nbr || *col_nbr != j)
	{
		ft_error("Provide rectangular maps only");
		exit(0);
	}
}

void	validate_map(char **map, int line_nbr)
{
	int		i;
	int		j;
	int		col_nbr;
	t_qty	*qty;

	i = 0;
	qty = malloc(sizeof(t_qty));
	qty->c = 0;
	qty->e = 0;
	qty->p = 0;
	col_nbr = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			validate_composition(map[i][j], qty);
			validate_walls(map[i], line_nbr, j, i);
			j++;
		}
		validate_shape(line_nbr, &col_nbr, i, j);
		i++;
	}
}
