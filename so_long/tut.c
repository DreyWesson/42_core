/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:05:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/04 20:54:55 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"
// #include<math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// int offset = (y * line_length + x * (bits_per_pixel / 8));
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

double sqrt(double a) {
    
	double i = 0;
	double j = a / 2;

	while (j != i)
	{
		i = j;
		j = (a / i + i) / 2;
	}
  
	return j;
}
int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (pixels);
}

int mouse_event(int button, int x, int y, void *param)
{
    // Whenever the event is triggered, print the value of button to console.
    ft_putnbr_fd(button, 1);
}

int	main(void)
{
	void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 1024, 640, "Tutorial Window");
    // mlx_pixel_put(mlx, win, 1024/2, 640/2, 0xFFFFFF);
	// draw_line(mlx, win, 1024, 640, 0, 0, 0xFFFFFF);
	mlx_mouse_hook(win, &mouse_event, 0);
    mlx_loop(mlx);
}
