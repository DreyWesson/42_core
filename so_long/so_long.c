/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:05:51 by doduwole          #+#    #+#             */
/*   Updated: 2023/05/04 21:28:45 by doduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

// int offset = (y * line_length + x * (bits_per_pixel / 8));
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
	// void	*mlx;
	// t_data	img;

	// mlx = mlx_init();
	// img.img = mlx_new_image(mlx, 1920, 1080);

	// /*
	// ** After creating an image, we can call `mlx_get_data_addr`, we pass
	// ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	// ** then be set accordingly for the *current* data address.
	// */
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// }

// int rgb_to_int(double r, double g, double b)
// {
//     int color = 0;
//     color |= (int)(b * 255);
//     color |= (int)(g * 255) << 8;
//     color |= (int)(r * 255) << 16;
//     return (color);
// }

// double sqrt(double a) {
    
// 	double i = 0;
// 	double j = a / 2;

// 	while (j != i)
// 	{
// 		i = j;
// 		j = (a / i + i) / 2;
// 	}
  
// 	return j;
// }
// int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
// {
// 	double deltaX = endX - beginX; // 10
// 	double deltaY = endY - beginY; // 0
// 	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
// 	deltaX /= pixels; // 1
// 	deltaY /= pixels; // 0
// 	double pixelX = beginX;
// 	double pixelY = beginY;
// 	while (pixels)
// 	{
// 		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
// 		pixelX += deltaX;
// 		pixelY += deltaY;
// 		--pixels;
// 	}
// 	return (pixels);
// }
// void	ft_putnbr(int n)
// {
// 	if (n < 0)
// 	{
		
// 		write(1, "-", 1);
// 		if (n == -2147483648)
// 		{
// 			write(1, "2", 1);
// 			write(1, "147483648", 9);
// 		}
// 		n = -n;
// 	}
// 	if (n > 9)
// 	{
// 		ft_putnbr(n / 10);
// 		n %= 10;
// 	}
// 	if (n < 10)
// 	{
// 		n += '0';
// 		write(1, &n, 1);
// 	}

// }

// int mouse_event(int button, int x, int y, void *param)
// {
//     // Whenever the event is triggered, print the value of button to console.
//     ft_putnbr(button);
// 	(void)x;
// 	(void)y;
// 	(void)param;
// 	return (button);
// }

// int	main(void)
// {
// 	void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 1024, 640, "Tutorial Window");
//     // mlx_pixel_put(mlx, win, 1024/2, 640/2, 0xFFFFFF);
// 	// draw_line(mlx, win, 1024, 640, 0, 0, 0xFFFFFF);
// 	mlx_mouse_hook(win, &mouse_event, 0);
//     mlx_loop(mlx);
// }

// typedef struct  s_program
// {
//     void *mlx;
//     void *win;
// }               t_program;

// int mouse_event(int button, int x, int y, void *param)
// {
//     t_program *tutorial = param;
    
//     mlx_pixel_put(tutorial->mlx, tutorial->win, 640/2, 360/2, 0xFFFFFF);
// 	(void)button;
// 	(void)x;
// 	(void)y;
    
//     return (1);
// }

// int main()
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 640, 360, "Event Parameters");

//     t_program tutorial;
//     tutorial.mlx = mlx;
//     tutorial.win = win;

//     mlx_mouse_hook(win, &mouse_event, &tutorial);

//     mlx_loop(mlx);
// }

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Create Image");

    void *image = mlx_new_image(mlx, 640, 360);
    
    // The following code goes here.
	int pixel_bits;
int line_bytes;
int endian;
char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

int color = 0xABCDEF;

if (pixel_bits != 32)
    color = mlx_get_color_value(mlx, color);

for(int y = 0; y < 360; ++y)
for(int x = 0; x < 640; ++x)
{
    int pixel = (y * line_bytes) + (x * 4);

    if (endian == 1)        // Most significant (Alpha) byte first
    {
        buffer[pixel + 0] = (color >> 24);
        buffer[pixel + 1] = (color >> 16) & 0xFF;
        buffer[pixel + 2] = (color >> 8) & 0xFF;
        buffer[pixel + 3] = (color) & 0xFF;
    }
    else if (endian == 0)   // Least significant (Blue) byte first
    {
        buffer[pixel + 0] = (color) & 0xFF;
        buffer[pixel + 1] = (color >> 8) & 0xFF;
        buffer[pixel + 2] = (color >> 16) & 0xFF;
        buffer[pixel + 3] = (color >> 24);
    }
}
mlx_put_image_to_window(mlx, win, image, 0, 0);

    mlx_loop(mlx);
}