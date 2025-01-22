#include "fractol.h"

void	create_image(t_fractal *frac)
{
	int x;
	int y;

	y = 0;
	while (y <= SIZE_Y - 1)
	{
		x = 0;
		while( x <= SIZE_X)
		{
			if(frac->name == JULIA)
				frac->buffer[((y * frac->size_line) + x * 4)/1] = julia(frac, x, y) ;
			if(frac->name == MANDEL)
				frac->buffer[((y * frac->size_line) + x * 4)/1] = mandel(frac, x, y) ;
			x++;
		}
		y++;
	}
}

void	create_image_pixel(t_fractal *frac)
{
	int x;
	int y;
	int color;
	int i;

	i = 0;
	while (i <12)
	{
		y = 50 + i*50;
		while (y <= 100 + i*50)
		{
			x = 50 +i*50;
			while( x <= 100+i*50)
			{
				color =  0x010000*30*i;
				mlx_pixel_put(frac->mlx, frac->window, x, y, color);

				x++;
			}
			y++;
		}
	printf("i = %d, color = %d\n", i, color);
	i++;
	}
}

int exit_fractol(t_fractal *frac)
{
	mlx_destroy_image(frac->mlx, frac->image);
//	mlx_destroy_window(frac->mlx, frac->image);
	free(frac->mlx);
	free(frac);
	exit(EXIT_SUCCESS);
	return (0);
}

void	error(void)
{
	ft_putendl_fd("entrez un des 2 parametres : julia ou mandel", 1);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
	t_fractal	*frac;

	frac = NULL;
	frac = init(frac, argc, argv);
	init_value(frac);
	create_image(frac);
	mlx_mouse_hook(frac->window, mouse_hook, frac);
	mlx_key_hook(frac->window, key_hook, frac);
	mlx_hook(frac->window, 17, 0L, exit_fractol, frac);
	mlx_put_image_to_window(frac->mlx, frac->window, frac->image, 0, 0);

	create_image_pixel(frac);

	mlx_loop(frac->mlx);
	return(0);
}
