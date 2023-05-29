/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 07:45:52 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/29 11:58:31 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


int line_counter(char *file_name)
{
	int i;
	int fd;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd))
		i++;
	return (i);
}


size_t	ft_strlen_ln(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	**map_reader(char *s, int line_nbr)
{
	char	**ptr;
	char	*str;
	int		i;
	int		len;
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Some error occurred");
		exit(1);
	}
	line_nbr = line_counter(s);
	ptr = (char **)ft_calloc(sizeof(char *), line_nbr + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (i < line_nbr)
	{
		str = get_next_line(fd);
		len = ft_strlen_ln(str);
		ptr[i] = ft_substr(str, 0, len);
		ptr[i][len] = '\0';
		i++;
	}
	return (ptr);
}
/**
 * [✅] only contains "01CEP"
 * [✅] must contain only one C/E/P
 * [✅] all first & last row and first & last cols are 1s ELSE return error
 * [✅] must be rectangular ie the num of cols must be greater than rows
 * [🔴] check if there’s a valid path in the map.
 * [🔴] If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way
*/

void validate_qty(char s, int *c, int *e, int *p)
{
	if (s == 'C')
		*c += 1;
	else if (s == 'E')
		*e += 1;
	else if (s == 'P')
		*p += 1;
	if (*c > 1 || *e > 1 || *p > 1)
	{
		ft_error("Invalid composition quantity");
		exit(0);
	}
}

void	validate_map(char **map, int line_nbr)
{
	int i;
	int j;
	int col_nbr;
	char *set;
	t_qty qty;

	set = "01CEP";
	i = 0;
	qty.c = 0;
	qty.e = 0;
	qty.p = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(set, map[i][j]))
			{
				ft_error("Invalid composition");
				exit(0);
			}
			else
			{
				// validate_qty(map[i][j], &qty.c, &qty.e, &qty.p);

			}
			if (map[i][j] != '1' && (i == 0 || i == line_nbr - 1
					|| j == 0 || map[i][j + 1] == '\0'))
			{
				ft_error("Should be surrounded by walls");
				exit(0);
			}
			j++;
		}
		if (i == 0)
			col_nbr = j;
		if (j <= line_nbr || col_nbr != j)
		{
			ft_error("Provide rectangular maps only");
			exit(0);
		}
		i++;
	}
	// ft_printf("\n\n%s\n", map[line_nbr-1]);
}

void handle_map(char **argv)
{
	char **ptr;
	int line_nbr;

	line_nbr = line_counter(argv[1]);
	ptr = map_reader(argv[1], line_nbr);
	validate_map(ptr, line_nbr);
	// while (ptr[i])
	// {
	// 	ft_printf("%s\n", ptr[i]);
	// 	i++;
	// }
}