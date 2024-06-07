/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:21:34 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/06 19:13:09 by jsobreir         ###   ########.fr       */
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
	printf("%06x\n" , r << 16 | g << 8 | b);
	return (r << 16 | g << 8 | b);
}

void	put_pixel(int pix, int piy, t_fractal *fractal,int iterations)
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
