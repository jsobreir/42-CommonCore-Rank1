/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:19:59 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/27 16:29:56 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		color_rgb(int n, int n_max)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (n == n_max)
		return (0);
	t = (double)n / (double)n_max;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (r << 16 | g << 8 | b);
}

void	put_pixel(int pix, int piy, t_fractal *fractal, int iterations)
{
	char		*addr;
	int			offset;
	int			color;

	color = color_rgb(iterations, MAX_ITERATIONS);
	addr = fractal->img.addr;
	offset = piy * fractal->img.line_len + pix * (fractal->img.bpp / 8);
	addr[offset] = color & 0xFF; // blue
	addr[offset + 1] = (color >> 8) & 0xFF; // green
	addr[offset + 2] = (color >> 16) & 0xFF; // red
}

void	handle_pixel(t_fractal *fractal, int pix, int piy)
{
	int			color;
	t_complex	*z;
	
	z = &fractal->z;
	if (ft_strcmp(fractal->name, "mandelbrot"))
		color = mandelbrot(fractal, pix, piy);
	else if (ft_strcmp(fractal->name, "julia"))
		color = julia(fractal, pix, piy);
	else
		return ;
	put_pixel(pix, piy, fractal, color);
}

void	render_fractol(t_fractal *fractal)
{
	int			x;
	int			y;
	
	mlx_clear_window(fractal->mlx, fractal->mlx_win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win,
		fractal->img.img, 0, 0);
}
