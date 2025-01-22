# include "fractol.h"

int	mouse_hook (int button, int x, int y, t_fractal *frac)
{
	printf("touche : %d  x = %d  y = %d\n", button, x, y);

	if (button == SCROLL_UP)
	{
		frac->zoom = frac->zoom * frac->growth;
		frac->o_x = frac->o_x - (SIZE_X/2 - x)*frac->growth;
		frac->o_y = frac->o_y - (SIZE_Y/2 - y)*frac->growth;
	}
	else if (button == SCROLL_DOWN)
	{
		frac->zoom = frac->zoom / frac->growth;
		frac->o_x = frac->o_x - (SIZE_X/2 - x)/frac->growth;
		frac->o_y = frac->o_y - (SIZE_Y/2 - y)/frac->growth;
	}
		else if (button == CLICK_L)
	{
	//	frac->zoom = frac->zoom * frac->growth;
		frac->o_x = frac->o_x - (SIZE_X/2 - x);
		frac->o_y = frac->o_y - (SIZE_Y/2 - y);
	}
	create_image(frac);
	mlx_put_image_to_window(frac->mlx, frac->window, frac->image, 0, 0);

	return(0);
}

int	key_hook (int button, t_fractal *frac)
{
	printf("touche : %d\n", button);
	if (button == ESC)
		exit_fractol(frac);
	else if (button == LEFT)
		frac->o_x -= frac->move;
	else if (button == RIGHT)
		frac->o_x += frac->move;
	else if (button == UP)
		frac->o_y -= frac->move;
	else if (button == DOWN)
		frac->o_y += frac->move;
	else if (button == R)
		init_value(frac);
	else if (button == P && frac->max_iter <= 500)
		frac->max_iter +=  30;
	else if (button == M && frac->max_iter >= 35)
		frac->max_iter -= 30;
	else
		key2(button, frac);

	create_image(frac);
	mlx_put_image_to_window(frac->mlx, frac->window, frac->image, 0, 0);
	return(0);
}

void	key2(int button, t_fractal *frac)
{
	if (button == PLUS && frac->max_iter <= 500)
		frac->zoom *= frac->growth;
	else if (button == MOINS && frac->max_iter >= 35)
		frac->zoom /= frac->growth;
	else if (button == N3)
		frac->pa += frac->p;
	else if (button == N1)
		frac->pa -= frac->p;
	else if (button == N5)
		frac->pb += frac->p;
	else if (button == N2)
		frac->pb -= frac->p;
//	else if (button == N7)
//		frac->color += 0x010000*30;
//	else if (button == N8)
//		frac->color = 11796480;
	else if (button == N9)
		frac->color += 0x000001*30;
//	else if (button == DIV)
//		frac->color = 0x000000;
	else if (button == MULT)
		frac->color = 0xFCBE11;
	printf("color = %d\n", frac->color);
}
