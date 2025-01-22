#include"fractol.h"


t_fractal *init(t_fractal *frac, int argc, char** argv)
{
	if(argc <= 1)
		error();
	frac = malloc(sizeof(t_fractal));
	frac->name = OTHER;
	if(ft_strncmp(argv[1], "julia", 6) == 0)
		frac->name = JULIA;
	if(ft_strncmp(argv[1], "mandel", 7) == 0)
		frac->name = MANDEL;
	if(ft_strncmp(argv[1], "ship", 5) == 0)
		frac->name = SHIP;
		if(frac->name == OTHER)
	{
		free(frac);
		error();
	}
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
	frac->o_x = -700;
	frac->o_y = -400;
	frac->color = 0xFCBE11;
	frac->zoom = 250;
	frac->growth = 1.2;
	frac->max_iter = 50;
	frac->p = 0;
	frac->pa = 0;
	frac->pb = 0;
	frac->move = 50;
	if(frac->name == JULIA)
	{
		frac->o_x = -550;
		frac->o_y = -375;
		frac->p = 0.05;
		frac->pa = -0.16;
		frac->pb = 0.88;
	}

}
