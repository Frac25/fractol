#include "fractol.h"

int mandel(t_fractal *frac, int x, int y)
{
	int i;
	int max;
	double zx;
	double zy;
	double cx;
	double cy;
	double temp;

	max = 100;
	zx = 0.0;
	zy = 0.0;
	cx = frac->o_x + x/frac->zoom;
	cy = frac->o_y + y/frac->zoom;

//	int colorb = 0xABCDEF; //bleu
	int color = 0xFCBE11; //

	i = 0;
	while (i < max)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2. * zx * zy + cy;
		zx = temp;
		if (zx * zx + zy * zy >= 1000)
		{
			return(color * i);
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
