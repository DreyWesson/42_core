/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/12 16:49:06 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_qty
{
	int c;
	int e;
	int p;
} t_qty;

typedef struct s_nodes
{
	
} t_nodes;

typedef struct s_coord
{
	int x;
	int y;
} t_coord;


enum	e_space_type
{
	EMPTY,
	COLLECTIBLES,
	EXIT
};

enum	e_status
{
	IDLE,
	WAITING,
	VISITED
};


/**
 * UTILS FUNCTION
*/
int		ft_error(char *message);
void	ft_warning(char *message);
int		ft_trim(char const *s1, char const *set);
int		handle_validation(int argc, char **argv);
/**
 * MAP -> Reader
*/
void 	handle_map(char **argv);
void	validate_map(char **map, int line_nbr);
int		line_counter(char *file_name);
size_t	ft_strlen_ln(const char *str);
char	**map_reader(char *s, int line_nbr);
/**
 * MAP -> Validator
*/
void	validate_composition(char s, t_qty *qty);
void validate_walls(char *s, int line_nbr, int j, int i);
void	validate_shape(int line_nbr, int *col_nbr, int i, int j);
t_coord	save_start(int x, int y);
void	check_quant(t_qty *qty);
void	default_quant(t_qty *qty);
#endif