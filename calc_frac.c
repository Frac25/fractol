#include "fractol.h"

int	mandel(t_fractal *frac, int x, int y)
{
	int	i;
	double	zx;
	double	zy;
	double	temp;

	zx = 0.0;
	zy = 0.0;
	frac->cx = (frac->o_x + x)/frac->zoom;
	frac->cy = (frac->o_y + y)/frac->zoom;
	i = 0;
	while (i < frac->max_iter)
	{
		temp = zx * zx - zy * zy + frac->cx;
		zy = 2. * zx * zy + frac->cy;
		zx = temp;
		if (zx * zx + zy * zy >= 1000)
		{
			return(frac->color + ((i % 255) * 10));
		}
		i++;
	}
	return(0);
}


int	julia(t_fractal *frac, int x, int y)
{
	int	i;
	double	zx;
	double	zy;
	double	temp;

	zx = (x + frac->o_x)/frac->zoom;
	zy = (y + frac->o_y)/frac->zoom;
	frac->cx = frac->pa;
	frac->cy = frac->pb;
	i = 0;
	while (i < frac->max_iter)
	{
		temp = zx * zx - zy * zy + frac->cx;
		zy = 2. * zx * zy + frac->cy;
		zx = temp;
		if (zx * zx + zy * zy >= __DBL_MAX__)
		{
			return(frac->color + ((i % 255) * 10));
		}
		i++;
	}
	return(0);
}

int	ship(t_fractal *frac, int x, int y)
{
	int	i;
	double	zx;
	double	zy;
	double	temp;

	zx = 0;
	zy = 0;
	frac->cx = (x + frac->o_x) / frac->zoom;
	frac->cy = (y + frac->o_y) / frac->zoom;
	i = 0;
	while (i < frac->max_iter)
	{
		temp = zx * zx - zy * zy + frac->cx;
		zy = fabs(2. * zx * zy + frac->cy);
		zx = fabs(temp);
		if (zx * zx + zy * zy >= __DBL_MAX__)
		{
			return(frac->color + ((i % 255) * 10));
		}
		i++;
	}
	return(0);
}
