#include "fractol.h"

int mandel(int x, int y)
{
	int i;
	int max;
	double zx;
	double zy;
	double cx;
	double cy;
	double temp;
	double zoom;

	zoom = 300;

	max = 40;
	zx = 0.0;
	zy = 0.0;
	cx = -1.21 + x/zoom;
	cy = -1.21 + y/zoom;

//	cx = x/300 - 1.21;
//	cy = y/300 - 1.21;

	int colorb = 0xABCDEF; //bleu
	int colorn = 0x000000; // noir
	int color = 0xFCBE11; //

	i = 0;
	while (i < max)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2. * zx * zy + cy;
		zx = temp;
//		if (zx * zx + zy *zy >= __DBL_MAX__)
		if (x >= 75 && x <= 85 && y >= 100 && y <= 100)
		{
			printf("i = %d, x = %d, y = %d, zx = %f zy = %f\n ", i, x, y, zx, zy);
			return(colorn);
		}
		if (zx * zx + zy * zy >= 1000)
		{
			return(color * i);
		}
		i++;
	}
	return(colorn);
}
/*
	if ( i >= max -1 )
	{
//		printf("1");
		return (1);
	}
	else
	{
//		printf("0");
		return (0);
	}
}
*/

/*
		if (zx * zx + zy * zy >= 4)
		{
			break ;
		}
		i++;
	}
	if ( i >= max -1 )
	{
//		printf("1");
		return (1);
	}
	else
	{
//		printf("0");
		return (0);
	}

	*/
