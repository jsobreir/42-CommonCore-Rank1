/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:12:50 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/07 19:06:29 by jsobreir         ###   ########.fr       */
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

int	close_window(int keycode, t_fractal *img)
{
	if (keycode == KEY_ESC)
		clean_exit(0, img);
	return (0);
}
