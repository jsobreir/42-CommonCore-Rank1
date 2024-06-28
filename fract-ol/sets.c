/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:49:43 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/28 12:26:44 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double		map(double unscaled_num, double new_min, double new_max, double old_max, double disp)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min + disp);
}

static t_complex	square_complex(t_complex *z, t_complex *c)
{
	t_complex	result;
	result.re = z->re * z->re - z->im * z->im + c->re;
	result.im = 2 * z->re * z->im + c->im;
	result.mod_squared = result.re * result.re + result.im * result.im;
	return (result);
}

int	mandelbrot(t_fractal *fractal, int pix, int piy)
{
	int			color;
	t_complex	c;
	int			scale;
	
	scale = fractal->scale;
	fractal->z.re = map(pix, fractal->x_min/scale, fractal->x_max/scale, WIDTH, fractal->disp_x);
	fractal->z.im = map(piy, fractal->y_min/scale, fractal->y_max/scale, HEIGHT, fractal->disp_y);
	// Calculate the first mod squared
	c.re = fractal->z.re;
	c.im = fractal->z.im;
	fractal->z.mod_squared = fractal->z.re * fractal->z.re + fractal->z.im * fractal->z.im;
	color = 0;
	while (color < MAX_ITERATIONS && fractal->z.mod_squared <= 4)
	{
		// Update the square complex
		fractal->z = square_complex(&fractal->z, &c);
		color++;
	}
	return (color);
}

int	julia(t_fractal *fractal, int pix, int piy)
{
	int			scale;
	int			color;
	t_complex	*c;
	t_complex	z;

	c = &fractal->z;
	scale = fractal->scale;
	z.re = map(pix, fractal->x_min/scale, fractal->x_max/scale, WIDTH, fractal->disp_x);
	z.im = map(piy, fractal->y_min/scale, fractal->y_max/scale, HEIGHT, fractal->disp_y);
	// Calculate the first mod squared
	z.mod_squared = z.re * z.re + z.im * z.im;
	color = 0;
	while (color < MAX_ITERATIONS && z.mod_squared <= 4)
	{
		// Update the square complex
		z = square_complex(&z, c);
		color++;
	}
	return (color);
}
