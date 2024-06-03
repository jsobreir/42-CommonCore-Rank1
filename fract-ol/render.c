/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:19:59 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/02 16:59:52 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		*map(double max, double min, int dim)
{
	double diff;
	double	step;
	double	*ret;
	double	*ret_temp;

	diff = max - min;
	step = diff / dim;
	ret = malloc(dim * sizeof(double));
	if (!ret)
		return (0);
	ret_temp = ret;
	while (min<= max)
	{
		*ret = min;
		ret++;
		min = min + step;
	}
	return (ret_temp);
}

t_complex *square_complex(t_complex *z)
{
	double	re;
	double	im;

	re = z->re;
	im = z->im;
	re = re * re - im * im;
	im = 2 * re * im;
	return (z);
}

void	handle_pixel(t_fractal *fractal, int pix, int piy)
{
	double		*x;
	double		*y;
	t_complex 	*z;
	int			color;
	
	if (fractal->name == "mandelbrot")
	{
			
	}
	color = 0;
	x = map(fractal->x_min, fractal->x_max, WIDTH);
	y = map(fractal->y_min, fractal->y_max, HEIGHT);
	while (color < MAX_ITERATIONS)
	{
		z->re = x[pix];
		z->im = y[piy];
		z = square_complex(z);
		if (z->re > fractal->x_max || z->im > fractal->y_max
			|| z->re < fractal->x_min || z->im < fractal->y_min)
			break;
	}
	// z**2 = (re + im*i)*(re + im*i) = re**2 + 2*re*im*i - im**2
	color_pixel(pix, piy, color); // TODO
}

void	render_fractol(t_fractal *fractal)
{
	int			x;
	int			y;
	char		*addr;
	t_img		*img_data;

	img_data = mlx_get_data_addr(img_data->img, img_data->bpp, img_data->line_len, img_data->endian);
	
	
	while (++y < HEIGHT)
	{
		while (++x < WIDTH)
		{
			handle_pixel(fractal, x, y);
			
			x++;
		}
		y++;
	}
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