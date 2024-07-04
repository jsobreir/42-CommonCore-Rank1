/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:40:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/04 16:05:33 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	zoom(t_fractal *fractal, double scale)
{
	double	center_x;
	double	center_y;

	center_x = fractal->x_max - fractal->x_min;
	center_y = fractal->y_max - fractal->y_min;
	fractal->x_max = fractal->x_max + (center_x - scale * center_x) / 2;
	fractal->x_min = fractal->x_min - (center_x - scale * center_x) / 2;
	fractal->y_max = fractal->y_max + (center_y - scale * center_y) / 2;
	fractal->y_min = fractal->y_min - (center_y - scale * center_y) / 2;
	return (0);
}

static int	move(int keycode, t_fractal *fractal, double distance)
{
	double	sensitivity;

	sensitivity = 0.1;
	if (keycode == K_AR_D) // Assuming down
		fractal->disp_y += (sensitivity * distance);
	else if (keycode == K_AR_U) // Assuming up
		fractal->disp_y -= (sensitivity * distance);
	else if (keycode == K_AR_R) // Assuming right
		fractal->disp_x += (sensitivity * distance);
	else if (keycode == K_AR_L) // Assuming left
		fractal->disp_x -= (sensitivity * distance);
	return (0);
}

static int	key_hooks(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESC)
		clean_exit(fractal);
	else if (keycode == K_AR_D || keycode == K_AR_U ||
			keycode == K_AR_L || keycode == K_AR_R)
		move(keycode, fractal, 1);
	else if (keycode == K_1)
		fractal->name = "mandelbrot";
	else if (keycode == K_2)
	{
		fractal->name = "julia";
		fractal->z.re = 0.43;
		fractal->z.im = 0.33;
	}
	else if (keycode == K_R)
	{
		fractal->disp_x = 0;
		fractal->disp_y = 0;
		fractal->scale = 1;
		fractal->x_max = 2;
		fractal->x_min = -2;
		fractal->y_max = 2;
		fractal->y_min = -2;
	}
	render_fractol(fractal);
	return (0);
}

int	on_key_press(int keycode, t_fractal *fractal)
{
	if (keycode == K_J)
		fractal->j_pressed = 1;
	else if (keycode == K_K)
		fractal->k_pressed = 1;
	key_hooks(keycode, fractal);
	return (0);
}

int	on_key_release(int keycode, t_fractal *fractal)
{
	if (keycode == K_J)
		fractal->j_pressed = 0;
	else if (keycode == K_K)
		fractal->k_pressed = 0;
	return (0);
}

int	fluid_hooks(t_fractal *fractal)
{
	if (fractal->j_pressed == 1)
	{
		fractal->z.re -= 0.01;
		fractal->z.im -= 0.01;
		ft_printf("New Julia set with c = %f + %fi\n",
			fractal->z.re, fractal->z.im);
		render_fractol(fractal);
	}
	else if (fractal->k_pressed == 1)
	{
		fractal->z.re += 0.01;
		fractal->z.im += 0.01;
		ft_printf("New Julia set with c = %f + %fi\n",
			fractal->z.re, fractal->z.im);
		render_fractol(fractal);
	}
	return (0);
}

static int	color_picker(t_fractal *fractal, int keycode)
{
	char	*set;

	set = fractal->color_set;
	if (keycode == MOUSE_LEFT &&
		ft_strncmp(fractal->color_set, "greyscale", 9) == 0)
	{
		fractal->color_set = "rainbow";
		ft_printf("Energy color palette set.\n");
	}
	else if (keycode == MOUSE_LEFT &&
		ft_strncmp(fractal->color_set, "rainbow", 7) == 0)
	{
		fractal->color_set = "heatmap";
		ft_printf("Bloody color palette set.\n");
	}
	else if (keycode == MOUSE_LEFT &&
		ft_strncmp(fractal->color_set, "heatmap", 7) == 0)
	{
		fractal->color_set = "psychadelic";
		ft_printf("Gold color palette set.\n");
	}
	else if (keycode == MOUSE_LEFT &&
		ft_strncmp(fractal->color_set, "psychadelic", 11) == 0)
	{
		fractal->color_set = "greyscale";
		ft_printf("Grey color palette set.\n");
	}
	return (0);
}

int	mouse_hooks(int keycode, int x, int y, t_fractal *fractal)
{
	double	distance_x;
	double	distance_y;

	if (keycode == MOUSE_WHEEL_UP || keycode == MOUSE_WHEEL_DOWN)
	{
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (keycode == MOUSE_WHEEL_DOWN)
			zoom(fractal, fractal->scale / 1.1);
		else if (keycode == MOUSE_WHEEL_UP)
			zoom(fractal, fractal->scale * 1.1);
		distance_x = (fractal->x_max - fractal->x_min) * (double)x / WIDTH;
		distance_y = (fractal->y_max - fractal->y_min) * (double)y / HEIGHT;
		if (x > 0)
			move(K_AR_R, fractal, distance_x);
		else if (x < 0)
			move(K_AR_L, fractal, -distance_x);
		if (y > 0)
			move(K_AR_D, fractal, distance_y);
		else if (y < 0)
			move(K_AR_U, fractal, -distance_y);
	}
	if (keycode == MOUSE_LEFT)
		color_picker(fractal, keycode);
	render_fractol(fractal);
	return (0);
}
