/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/29 11:47:25 by doduwole         ###   ########.fr       */
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
void handle_map(char **argv);

#endif