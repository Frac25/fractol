/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydubois <sydubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:20:10 by sydubois          #+#    #+#             */
/*   Updated: 2025/01/28 12:29:49 by sydubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_image(t_fractal *f)
{
	int	x;
	int	y;

	y = 0;
	while (y <= SIZE_Y - 1)
	{
		x = 0;
		while (x <= SIZE_X)
		{
			if (f->name == JULIA)
				f->buffer[((y * f->s_l) + x * f->bpp / 8)] = julia(f, x, y);
			if (f->name == MANDEL)
				f->buffer[((y * f->s_l) + x * f->bpp / 8)] = mandel(f, x, y);
			if (f->name == SHIP)
				f->buffer[((y * f->s_l) + x * f->bpp / 8)] = ship(f, x, y);
			x++;
		}
		y++;
	}
}

void	create_image_pixel(t_fractal *frac)
{
	int	x;
	int	y;
	int	color;
	int	i;

	i = 0;
	while (i <= 10)
	{
		y = 120;
		while (y <= 125)
		{
			x = 10 + i * 10;
			while (x <= 20 + i * 10)
			{
				color = 0x010000 * 20 * i;
				mlx_pixel_put(frac->mlx, frac->window, x, y, color);
				x++;
			}
			y++;
		}
	i++;
	}
}

void	print_logo(t_fractal *frac)
{
	char	*img_logo;
	int		width;
	int		height;
	void	*logo;

	img_logo = "./fractol_image_100x100.png";
	width = 100;
	height = 100;
	logo = mlx_png_file_to_image(frac->mlx, img_logo, &width, &height);
	if (!logo)
	{
		printf("probleme logo %s et l = %s\n ", img_logo, logo);
	}
	mlx_put_image_to_window(frac->mlx, frac->window, logo, 0, 0);
}
