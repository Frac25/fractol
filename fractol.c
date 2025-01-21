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
			frac->buffer[((y * frac->size_line) + x * 4)/1] = julia(frac, x ,y) ;
			x++;
		}
		y++;
	}
//	return (buffer);
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

t_fractal	*init(t_fractal *frac)
{
	frac = malloc(sizeof(t_fractal));
	// a proteger et leaks
	frac->mlx = mlx_init ();
	frac->window = mlx_new_window(frac->mlx, SIZE_X, SIZE_Y, "fractol");
	frac->image = mlx_new_image(frac->mlx, SIZE_X, SIZE_Y);
	frac->bits_per_pixel = 32;
	frac->size_line = SIZE_X * frac->bits_per_pixel;
	frac->endian = 0;
	frac ->buffer = mlx_get_data_addr(frac->image, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
	return (frac);
}

void init_value(t_fractal *frac)
{
	frac->zoom = 250;
	frac->growth = 1.1;
//	frac->o_x = -700;
//	frac->o_y = -400;
	frac->o_x = -200;
	frac->o_y = 5;
	frac->move = 50;
	frac->max_iter = 50;
}

int main(void)
{
	t_fractal	*frac;

	frac = NULL;
	frac = init(frac);
	init_value(frac);
	create_image(frac);
	mlx_mouse_hook(frac->window, mouse_hook, frac);
	mlx_key_hook(frac->window, key_hook, frac);
	mlx_hook(frac->window, 17, 0L, exit_fractol, frac);
	mlx_put_image_to_window(frac->mlx, frac->window, frac->image, 0, 0);
	mlx_loop(frac->mlx);
	return(0);
}
