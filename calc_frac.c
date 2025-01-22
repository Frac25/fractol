#include "fractol.h"

int mandel(t_fractal *frac, int x, int y)
{
	int i;
	double zx;
	double zy;
	double cx;
	double cy;
	double temp;

	zx = 0.0;
	zy = 0.0;
	cx = (frac->o_x + x)/frac->zoom;
	cy = (frac->o_y + y)/frac->zoom;
	i = 0;
	while (i < frac->max_iter)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2. * zx * zy + cy;
		zx = temp;
		if (zx * zx + zy * zy >= 1000)
		{
			return(frac->color * i);
		}
		i++;
	}
	return(0);
}


int julia(t_fractal *frac, int x, int y)
{
	int i;
	double zx;
	double zy;
	double cx;
	double cy;
	double temp;

	zx = (x + frac->o_x)/frac->zoom;
	zy = (y + frac->o_y)/frac->zoom;
	cx = frac->pa;
	cy = frac->pb;
	i = 0;
	while (i < frac->max_iter)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2. * zx * zy + cy;
		zx = temp;
		if (zx * zx + zy * zy >= __DBL_MAX__)
		{
			return(frac->color * i);
		}
		i++;
	}
	return(0);
}


//		if (x >= 75 && x <= 85 && y >= 100 && y <= 100)
//		{
//			printf("i = %d, x = %d, y = %d, zx = %f zy = %f\n ", i, x, y, zx, zy);
//			return(colorn);
//		}
