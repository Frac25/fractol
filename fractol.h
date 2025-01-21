#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "minilibx/mlx.h"

#define SIZE_X 1000
#define SIZE_Y 1000

// MOUSE
# define CLICK_L 1
# define CLICK_R 2
# define CLICK_S 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// KEYBOARD
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define P 35
# define M 46

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
	char	*buffer;
	double	zoom;
	double	growth;
	double	o_x;
	double	o_y;
	double	move;

}	t_fractal;

char	*create_image(t_fractal *frac, char *buffer);
int		exit_fractol(t_fractal *frac);

int		mandel(t_fractal *frac, int x, int y);

int		mouse_hook (int button, int x, int y, t_fractal *param);
int		key_hook (int button, t_fractal *param);

#endif


//man usr/share/man/man3/mlx.1
