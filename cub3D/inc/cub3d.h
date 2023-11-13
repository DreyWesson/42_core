/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:22:48 by doduwole          #+#    #+#             */
/*   Updated: 2023/11/12 01:17:14 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

// MLX_LIB
# ifdef __APPLE__
#  include "../mlx/mlx.h"
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define ESC 53
#  define ARROW_LEFT 123
#  define ARROW_RIGHT 124
#  define ARROW_DOWN 125
#  define ARROW_UP 123

# else
#  include "../minilibx-linux/mlx.h"
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define ESC 65307
#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
# endif

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define TILE_W  128
# define TILE_H 128
# define DEBUG 0
# define MOVE_SPEED 0.0275
# define ROT_SPEED 0.015

# define SHADOW 8355711
# define FOUR_BYTE 4

enum				e_status
{
	FAILURE = -42,
	SUCCESS = 0,
	TEXTURE_ADDED = 1
};

enum e_tex_idx
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			endian;
	int			size_line;
	int			pixel_bits;
}	t_img;

typedef struct s_point
{
	int			x;
	int			y;
}			t_point;

typedef struct s_player
{
	char		dir;
	int			x;
	int			y;
	double		pos_y;
	double		pos_x;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			move_x;
	int			move_y;
	int			rotate;
	int			has_moved;
}	t_player;

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	double		wall_x;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

typedef struct s_data
{
	char		**cub_file;
	char		*cub_path;
	int			cub_height;
	int			cub_fd;
	char		**map;
	int			map_height;
	int			map_width;
	int			map_end_idx;
	char		*north_tex;
	char		*east_tex;
	char		*south_tex;
	char		*west_tex;
	int			**textures;
	int			tex_size;
	int			**tex_pixels;
	int			tex_x;
	int			tex_y;
	int			win_height;
	int			win_width;
	int			*col_ceiling;
	int			*col_floor;
	int			col_ceiling_int;
	int			col_floor_int;
	t_player	player;
	void		*mlx_ptr;
	void		*mlx_win;
	int			tile_w;
	int			tile_h;
	int			tex_index;
	double		tex_step;
	double		tex_pos;
	t_ray		ray;
}	t_data;

/**
 * ******** PARSING  START ************
 */
int				parsing(t_data *data, char **argv);
/**
 * ******** EXTRACTORS ************
 */
int				add_colors(t_data *data, char *line, int j);
int				retrieve_file_data(t_data *data, char **cub_file);
int				add_map(t_data *data, char **cub_file, int i);
int				add_textures(t_data *data, char *line, int j);
/**
 * ******** FREE ************
 */
void			free_data(t_data *data);
void			free_colors(t_data *data);
void			free_textures(t_data *data);
void			free_cub(t_data *data);
void			free_array_2d(void **array_2d);
/**
 * ******** MAPS ************
 */
void			init_data(t_data *data);
/**
 * ******** MAPS ************
 */
void			make_map_rectangular(t_data *data);
void			handle_cub(char *cub_path, t_data *data);
/**
 * ******** PRINTER ************
 */
int				ft_error(char *message);
void			ft_err(char *message);
void			print_grid(char **map, int row_nbr);
void			print_array_2d(char **array_2d);
void			print_array_2d_newline(char **array_2d);
void			print_map(t_data *data, char *str);
void			print_all_data(t_data *data);
/**
 * ******** UTILS ************
 */
bool			ft_isspace(char c);
bool			ft_isprint_no_space(int c);
bool			is_texture_or_color(char c);
bool			is_texture(char c1, char c2);
int				is_last_char_one(const char *line);
void			clean_exit(t_data *data, int exitstatus);
char			*ft_strdup2(const char *s1, int len);
void			check_fd(int fd);
int				line_counter(char *file_name);
size_t			ft_strlen_ln(const char *str);
size_t			ft_strlen_no_newline(const char *str);
size_t			find_max_width(t_data *data, int i);
/**
 * ******** VALIDATIONS ************
 */
int				is_valid_exe(char *str, char *exe);
int				validate_map(t_data *data, char **map);
int				validate_textures(t_data *data);
int				validate_walls(t_data *data);
int				flood_fill(char **tab, t_point size, int x, int y);
/**
 * ******** PARSING  END ************
 */
/**
 * ******** BUILD GRAPHICS START ************
 */
void			handle_compass(t_data *data);
int				game_init(t_data *data);
void			texture_init(t_data *data);
void			render_frame(t_data *data);
void			update_texture_pixels(t_data *data, t_ray *ray, int x);
void			render_images(t_data *data);
int				ray_casting(t_data *data);
int				check_map_boundaries(t_data *data, t_ray *ray);
void			calc_line_height(t_ray *ray, t_data *data);
void			calc_px_filler(t_ray *ray, t_data *data);
void			calc_x_coord_pl_facing_left_up(t_data *data, t_ray *ray);
void			handle_vert_wall_px(t_data *data, t_ray *ray, int x);
int				update(t_data *data);
int				move_player(t_data *data);
int				rotate_player(t_data *data, double rotdir);
int				end_program(t_data *data);
int				build_graphics(t_data *data);
int				key_release(int key, t_data *data);
int				key_press(int key, t_data *data);
/**
 * ******** BUILD GRAPHICS END ************
 */
void			debugger(t_data *data);

#endif
