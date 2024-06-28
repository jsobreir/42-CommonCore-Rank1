/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:40:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/28 12:34:45 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	clean_exit(int exit_code, t_fractal *f)
{
	if (!f)
		exit(exit_code);
	if (f->img.img)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->mlx_win && f->mlx)
		mlx_destroy_window(f->mlx, f->mlx_win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(exit_code);
}

static int zoom(int keycode, t_fractal *fractal)
{
	double	sensitivity;

	sensitivity = 0.15 * fractal->scale;
	// printf("Entrou na zoom()\n");
	if (keycode == MOUSE_WHEEL_DOWN)
		fractal->scale += sensitivity;
	else if (keycode == MOUSE_WHEEL_UP)
		fractal->scale -= sensitivity;
	render_fractol(fractal);
	return 0;
}

// static int	drag(int x, int y, t_fractal *fractal)
// {
// 	fractal->disp_x = -(x - fractal->x);
// 	fractal->disp_y = -(y - fractal->y);
// 	fractal->x = x;
// 	fractal->y = y;
// 	render_fractol(fractal);
// 	return (0);
// }

// int mouse_pressed(int keycode, int x, int y, t_fractal *fractal)
// {
// 	printf("Entrou na mouse_pressed()\n");
// 	fractal->mouse_pressed = 1;
// 	if (keycode == MOUSE_WHEEL_DOWN || keycode == MOUSE_WHEEL_UP)
// 	{
// 		fractal->x = x;
// 		fractal->y = y;
// 	}
// 	return (0);
// }

// int mouse_released(int keycode, int x, int y, t_fractal *fractal)
// {
// 	printf("Entrou na mouse_released()\n");
// 	fractal->mouse_pressed = 0;
// 	if (keycode == MOUSE_WHEEL_DOWN || keycode == MOUSE_WHEEL_UP)
// 	{
// 		fractal->new_y = y;
// 		fractal->new_x = x;
// 		drag(x, y, fractal);
// 	}
// 	return (0);
// }

int move(int keycode, t_fractal *fractal)
{
	// printf("Entrou na move()\n");
    if (keycode == K_AR_D) // Assuming down
        fractal->disp_y += 0.5 / fractal->scale;
    else if (keycode == K_AR_U) // Assuming up
        fractal->disp_y -= 0.5 / fractal->scale;
    else if (keycode == K_AR_R) // Assuming right
        fractal->disp_x += 0.5 / fractal->scale;
    else if (keycode == K_AR_L) // Assuming left
		fractal->disp_x -= 0.5 / fractal->scale;
	render_fractol(fractal);
    return (0);
}

int	key_hooks(int keycode, t_fractal *fractal)
{
	// printf("Entrou na key_hooks()\n");
	if (keycode == KEY_ESC)
		clean_exit(0, fractal);
	else if (keycode == K_AR_D || keycode == K_AR_U || keycode == K_AR_L || keycode == K_AR_R)
	{
		while (1)
		{
			move(keycode, fractal);
			usleep(10000);
			if (!fractal->mouse_pressed)
				break;
		}
	}
	else if (keycode == 'j')
	{
		fractal->z.re -= 0.05;
		fractal->z.im -= 0.05;
		render_fractol(fractal);
	}
	else if (keycode == 'k')
	{
		fractal->z.re += 0.05;
		fractal->z.im += 0.05;
		render_fractol(fractal);
	}
	else if (keycode == '1')
	{
		fractal->name = "mandelbrot";
		render_fractol(fractal);
	}
		else if (keycode == '2')
	{
		fractal->name = "julia";
		render_fractol(fractal);
	}

	return (0);
}

int	mouse_hooks(int keycode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	// printf("Entrou na mouse_hooks()\n");
	if (keycode == MOUSE_WHEEL_UP || keycode == MOUSE_WHEEL_DOWN)
		zoom(keycode, fractal);
	// else if (keycode == MOUSE_LEFT && fractal->mouse_pressed == 0)
	// 	mouse_pressed(keycode, x, y, fractal);
	// else if (keycode == MOUSE_LEFT && fractal->mouse_pressed == 1)
	// 	mouse_released(keycode, x, y, fractal);
	return (0);
}
