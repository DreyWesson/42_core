/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:42:30 by ioduwole          #+#    #+#             */
/*   Updated: 2023/05/11 10:54:04 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef SIZE
#  define SIZE 60
#  define ESC_KEY 53
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_A 0
# endif

typedef struct s_data
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*space;
	int		exit;
	void	*character_img;
	int		img_wh;
	char	direction;
	void	*potion;
	void	*character[2];
	char	last_pos;
	void	*door[2];
	int		col;
	int		steps;
	int		player[2];
	int		potions;
	int		collected;
	int		row;
}	t_data;

int		checker(t_data *game, int fd);
int		free_destroy(t_data *game);
int		check_path(t_data *game, int **marked);
int		fline(char *tmp, int process);
int		get_map(t_data *game, char *argv[]);
int		is_path(t_data *game);
int		ft_key_hook(int keycode, t_data *game);
int		mid_lines(char *tmp, int len);
int		search_map(t_data *game);
void	change_position(t_data *game, int row, int col);
t_data	*validate_map(int argc, char *argv[]);
void	build_graphics(t_data *game);
void	build_game_potion(t_data *game);
void	build_wall_door(t_data *game);
void	clear_game(t_data *game);
void	init_data(t_data *game);
void	init_map(t_data *game);
void	is_exit(t_data *game, int row, int col);
void	mark_path(t_data *game, int row, int col, int **marked);
void	ft_put_img(t_data *game, void *img, int row, int col);
void	check_exit(t_data *game);

#endif