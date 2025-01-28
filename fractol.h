/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:37:00 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/28 12:38:35 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include <math.h>

# define SIZE_X 1000
# define SIZE_Y 700

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
# define R 15
# define N1 83
# define N2 84
# define N3 85
# define N5 87
# define N7 89
# define N8 91
# define N9 92
# define DIV 75
# define MULT 67
# define PLUS 69
# define MOINS 78

typedef enum name
{
	OTHER,
	JULIA,
	MANDEL,
	SHIP,
}	t_name;

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	int		s_l;
	int		bpp;
	int		endian;
	char	*buffer;
	t_name	name;
	double	pa;
	double	pb;
	double	p;
	double	zoom;
	double	growth;
	double	cx;
	double	cy;
	double	o_x;
	double	o_y;
	double	move;
	int		max_iter;
	int		color;

}	t_fractal;

void		display(t_fractal *frac);
int			exit_fractol(t_fractal *frac);
void		error(void);

t_fractal	*init(t_fractal *frac, int argc, char **argv);
void		init_value(t_fractal *frac);

void		create_image(t_fractal *frac);
void		print_logo(t_fractal *frac);
void		create_image_pixel(t_fractal *frac);

int			julia(t_fractal *frac, int x, int y);
int			mandel(t_fractal *frac, int x, int y);
int			ship(t_fractal *frac, int x, int y);

int			mouse_hook(int button, int x, int y, t_fractal *param);
int			key_hook(int button, t_fractal *param);
void		key2(int button, t_fractal *frac);

void		ft_putendl_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_itoa(int n);

#endif
