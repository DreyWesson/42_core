/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:05:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/27 07:24:17 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "./inc/so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	add_img_px(t_data *img)
{
	int	x;
	int	y;

    y = 0;
    while (y < 60)
    {
        x = 0;
        while (x < 60)
        {
            my_mlx_pixel_put(img, x, y, 0xFFFFFF);
            x++;
        }
        y++;
    }
}

int	main(void)
{
    void	*mlx;
	void	*mlx_win;
	t_data	img;

    int col;
    int row;
    row = 0;
    col = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 60 * 12, 60 * 8, "Hello world!");
	img.img = mlx_new_image(mlx, 60, 60);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	add_img_px(&img);
	while (row < 60*8)
	{
		col = 0;
		while (col < 60*12)
		{
			if (col != 0 || row != 0)
				mlx_put_image_to_window(mlx, mlx_win, img.img, col, row);
			col += 60;
		}
		row += 60;
	}
	mlx_loop(mlx);
}
