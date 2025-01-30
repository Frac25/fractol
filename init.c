/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:40:41 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/30 09:43:18 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

t_fractal	*init(int argc, char **argv)
{
	t_fractal	*f;

	if (argc <= 1)
		error();
	f = malloc(sizeof(t_fractal));
	f->name = OTHER;
	if (ft_strncmp(argv[1], "julia", 6) == 0)
		f->name = JULIA;
	if (ft_strncmp(argv[1], "mandel", 7) == 0)
		f->name = MANDEL;
	if (ft_strncmp(argv[1], "ship", 5) == 0)
		f->name = SHIP;
	if (f->name == OTHER)
	{
		free(f);
		error();
	}
	f->mlx = mlx_init ();
	f->window = mlx_new_window(f->mlx, SIZE_X, SIZE_Y, "fractol");
	f->image = mlx_new_image(f->mlx, SIZE_X, SIZE_Y);
	f->bpp = 32;
	f->s_l = SIZE_X * f->bpp;
	f->endian = 0;
	f ->buffer = mlx_get_data_addr(f->image, &f->bpp, &f->s_l, &f->endian);
	return (f);
}

void	init_value(t_fractal *f)
{
	f->o_x = -700;
	f->o_y = -400;
	f->color = 0xFCBE11;
	f->zoom = 250;
	f->growth = 1.2;
	f->max_iter = 50;
	f->p = 0;
	f->pa = 0;
	f->pb = 0;
	f->move = 50;
	if (f->name == JULIA)
	{
		f->o_x = -550;
		f->o_y = -375;
		f->p = 0.05;
		f->pa = -0.16;
		f->pb = 0.88;
	}
}
