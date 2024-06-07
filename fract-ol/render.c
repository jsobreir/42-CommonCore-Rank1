/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:19:59 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/07 19:49:04 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_complex square_complex(t_complex *z, t_complex c)
{
	t_complex	result;
	result.re = z->re * z->re - z->im * z->im + c.re;
	result.im = 2 * z->re * z->im + c.im;
	result.mod_squared = result.re * result.re + result.im * result.im;
	return (result);
}


void	handle_pixel(t_fractal *fractal, int pix, int piy, t_complex *z)
{
	int			color;
	t_complex	c;
	int scale = 0.4;
	z->re = 0;
	z->im = 0;
	if (ft_strcmp(fractal->name, "mandelbrot"))
	{
		fractal->x_max = scale * 2;
		fractal->x_min = -scale * 2;
		fractal->y_max = scale *1;
		fractal->y_min = -scale * 1;
	}
	color = 0;
	z->re = map(pix, fractal->x_min, fractal->x_max, WIDTH);
	z->im = map(piy, fractal->y_min, fractal->y_max, HEIGHT);
	c.re = z->re;
	c.im = z->im;
	z->mod_squared = z->re * z->re + z->im * z->im;
	while (color < MAX_ITERATIONS && z->mod_squared <= 4)
	{
		*z = square_complex(z, c);
		color++;
	}
	// printf("%f + %fi = %f : %d\n", x[pix], y[piy], z->mod_squared, color);
	put_pixel(pix, piy, fractal, color);
}

void	render_fractol(t_fractal *fractal)
{
	int			x;
	int			y;
	t_img		*img_data;
	t_complex 	z;

	img_data = &fractal->img;
	if (img_data == NULL)
	{
		fprintf(stderr, "Error: Image data address is NULL\n");
		return;
	}
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(fractal, x, y, &z);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		img_data->img, 0, 0);
}
/*
int main (void)
{
	double *ret;

	ret = map(2, -2, 800);
	while (*ret)
	{
		printf("%f\n", *ret);
		ret++;
	}
} */
