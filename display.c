#include "fractol.h"

void	create_image(t_fractal *frac)
{
	int	x;
	int	y;

	y = 0;
	while (y <= SIZE_Y - 1)
	{
		x = 0;
		while ( x <= SIZE_X)
		{
			if (frac->name == JULIA)
				frac->buffer[((y * frac->size_line) + x * frac->bits_per_pixel / 8)] = julia(frac, x, y);
			if (frac->name == MANDEL)
				frac->buffer[((y * frac->size_line) + x * frac->bits_per_pixel / 8)] = mandel(frac, x, y);
			if (frac->name == SHIP)
				frac->buffer[((y * frac->size_line) + x * frac->bits_per_pixel / 8)] = ship(frac, x, y);
			x++;
		}
		y++;
	}
}

void	create_image_pixel(t_fractal *frac)
{
	int	x;
	int	y;
	int	color;
	int	i;

	i = 0;
	while (i <= 10)
	{
		y = 120;
		while (y <= 125)
		{
			x = 10 + i * 10;
			while ( x <= 20 + i * 10 )
			{
				color =  0x010000*20 * i;
				mlx_pixel_put(frac->mlx, frac->window, x, y, color);
				x++;
			}
			y++;
		}
	i++;
	}
}

void	print_logo(t_fractal *frac)
{
	char	*img_logo;
	int		width;
	int		height;
	void	*logo;

	img_logo = "./fractol_image_100x100.png";
	width = 100;
	height = 100;
	logo = mlx_png_file_to_image(frac->mlx, img_logo, &width, &height);
	if (!logo)
	{
		printf("probleme logo %s et l = %s\n ", img_logo, logo);
	}
	mlx_put_image_to_window(frac->mlx, frac->window, logo, 0, 0);
}
