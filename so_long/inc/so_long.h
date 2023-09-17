/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 09:31:50 by doduwole          #+#    #+#             */
/*   Updated: 2023/09/04 20:52:19 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// MLX_LIB
# ifdef __APPLE__
#  include "../mlx/mlx.h"
# else
#  include "../minilibx-linux/mlx.h"
# endif

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifdef __APPLE__
#  define A 0
#  define S 1
#  define D 2
#  define W 13
#  define R 15
#  define X 53
# else
#  define A 97
#  define S 115
#  define D 100
#  define W 119
#  define R 15
#  define X 65307
# endif

# define IMG_SIZE 64

enum	e_status
{
	SPACE = '0',
	BLOCK = '1',
	WAITING = '2',
	VISITED = '3'
};

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
}	t_tiletype;

typedef enum e_compass
{
	UP = 'U',
	DOWN = 'D',
	LEFT = 'L',
	RIGHT = 'R'
}	t_compass;

typedef struct s_quant
{
	int	collectibles;
	int	exit;
	int	player;
}	t_quant;

typedef struct s_axis
{
	int	x;
	int	y;
}	t_axis;

/* Color */
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;
typedef struct s_dir
{
	t_axis		coord;
	t_compass	arrow;
}	t_dir;

typedef struct s_details
{
	int		col_nbr;
	int		row_nbr;
	int		burger_nbr;
	int		cache_status;
	t_axis	cache_exit;
	t_axis	pos;
}	t_details;

typedef struct s_cell
{
	char			val;
	int				x_axis;
	int				y_axis;
	char			status;
	t_tiletype		type;
	t_tiletype		cache;
	t_axis			position;
	struct s_cell	*up;
	struct s_cell	*down;
	struct s_cell	*left;
	struct s_cell	*right;
}	t_cell;

typedef struct s_nodes
{
	t_cell			*cell;
	struct s_nodes	*next;
	struct s_nodes	*prev;
}	t_nodes;

typedef struct s_tile
{
	t_axis			position;
	t_tiletype		type;
	t_tiletype		mem_type;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_player
{
	void	*current_img;
	int		frame_count;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
	t_cell	*tile;
}	t_player;

typedef struct s_coll_img
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
	void	*img_2;
}	t_collect_img;

typedef struct s_wall_img
{
	void	*block;
	void	*north_west;
	void	*north;
	void	*north_east;
	void	*east;
	void	*south_east;
	void	*south;
	void	*south_west;
	void	*west;
}	t_wall_img;

typedef struct s_effect
{
	void		*img;
	int			frames;
	int			counter;
	t_axis		pos;
}	t_effect;

enum e_keycode
{
	KEY_UP = W,
	KEY_DOWN = S,
	KEY_LEFT = A,
	KEY_RIGHT = D,
	RESET = R,
	ESC = X
};

typedef struct s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_pixel;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				collects;
	int				moves;
	void			*door_open_img;
	void			*door_close_img;
	t_details		props;
	t_player		player;
	t_cell			**grid;
	t_effect		effect;
	t_axis			window_size;
	t_axis			img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	t_cell			current_cell;
}	t_game;

/**
 * UTILS FUNCTION
*/
int			ft_error(char *message);
void		ft_warning(char *message);
int			ft_trim(char const *s1, char const *set);
int			handle_validation(int argc, char **argv, t_game *game);
/**
 * MAP -> Reader
*/
int			handle_map(char **argv, t_game *game);
t_cell		**validate_map(char **map, t_details *details, t_nodes **queue);
int			line_counter(char *file_name);
size_t		ft_strlen_ln(const char *str);
char		**map_reader(char *s, int row_nbr);
/**
 * MAP -> Validator
*/
int			is_valid(char *str);
int			validate_composition(char s, t_quant *quant);
int			validate_walls(char *s, int row_nbr, int j, int i);
int			validate_shape(t_details *details, int i, int j);
void		save_start(int x, int y, t_details *details);
void		check_quant(char **map, t_quant *quant, t_details *details);
void		default_quant(t_quant *quant);
t_cell		create_cell(char s, int x, int y);
t_details	default_details(char *ptr);
void		print_grid(t_cell **grid, t_details details);
void		print_adjacent(t_details details, t_cell **grid);
void		print_end(int moves);
int			special_char(char **map);
t_cell		**create_grid(char **map, t_details *details);
void		handle_adjacency(t_cell **grid, t_nodes **queue);
t_cell		**validate_paths(t_cell **grid, t_nodes **queue,
				t_details	details, char **map);
int			check_paths(t_cell **grid, t_nodes **queue, t_details details);
t_cell		*adjacency_math(t_cell **grid,
				t_nodes **queue, int y, int x);
/**
 * QUEUE
*/
void		add_head_node(t_nodes **old, t_nodes *new);
void		print_node(t_nodes *head, int col_nbr);
void		add_tail_node(t_nodes **old, t_nodes *new);
void		del_node(t_nodes **head);
t_nodes		*last_node(t_nodes *head);
t_nodes		*create_node(t_cell *cell);
/**
 * FREE
*/
int			count_row(char **grid);
void		free_list(t_nodes **head_ref);
void		free_grid(t_cell **grid, int row_nbr, int status);
void		alt_free_grid(t_cell **grid, int row_nbr);
void		free_all(char **ptr, t_cell **grid, t_nodes **queue);
int			input(int key, t_game *game);
int			build_graphics(t_game *game, t_cell **grid, t_details props);
int			reset(t_game *game);
int			update(t_game *game);
void		render(t_game game);
int			draw_corner(t_game game, t_axis pos);
int			draw_sides(t_game game, t_axis pos);
void		draw_doors(t_game game, t_axis pos);
void		draw_collectible(t_game game, t_axis pos);
void		draw_player(t_game game, t_axis pos);
int			move_player(t_game *game, t_cell *tile);
void		draw_wall(t_game game, t_axis pos);
void		effect_anime(t_effect *effect, t_axis pos);
void		action_anime(t_player *player);
int			end_program(t_game *game);
int			load_images(t_game *game);
int			south_wall(t_game *game, int *x, int *y);
int			north_wall(t_game *game, int *x, int *y);
int			player_imgs_error(t_game game);
int			collectible_imgs_error(t_game game);
int			door_imgs_error(t_game game);
int			game_init(t_game *game, t_cell **grid, t_details details);
int			west_wall_error(t_wall_img wall);
int			east_wall_error(t_wall_img wall);
int			west_wall(t_game *game, int *x, int *y);
int			east_wall(t_game *game, int *x, int *y);
int			south_wall_error(t_wall_img wall);
int			north_wall_error(t_wall_img wall);
void		to_collectible(t_game *game, t_cell *tile);
void		to_exit(t_game *game, t_cell *tile);
void		to_empty(t_game *game, t_cell *tile);

#endif