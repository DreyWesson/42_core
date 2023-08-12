/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/08/12 10:12:51 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
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
 * MAP FUNCTIONS
*/
void 	handle_map(char **argv);
void	validate_map(char **map, int line_nbr);

#endif