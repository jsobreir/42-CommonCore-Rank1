/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:22:37 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/31 17:17:38 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	* INIT
	* ~mlx
	* ~listening events
	* ~hooks data
*/
static void	malloc_error(void)
{
	write(2, "Problems with Malloc", 20);
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (NULL == fractal->mlx)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx, 800, 800, "Fractol");
	if (NULL == fractal->mlx_win)
	{
		mlx_clear_window(fractal->mlx, fractal->mlx_win);
		free(fractal->mlx_win);
		malloc_error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx, HEIGHT, WIDTH);
	if (NULL == fractal->img.img)
	{
		mlx_destroy_image(fractal->mlx, fractal->img.img);
		free(fractal->img.img);
		malloc_error();
	}
}