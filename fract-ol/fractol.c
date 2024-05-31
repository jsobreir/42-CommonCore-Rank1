/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:13:41 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/31 18:24:56 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_fractal 	*fractal;
	// t_img		img;
	
	fractal_init(fractal);
	// fractal_render();
	mlx_new_window(fractal->mlx, WIDTH, HEIGHT, "Fractol");
	mlx_hook(fractal->mlx_win, 2, 1L<<0, close, fractal);
	mlx_loop(fractal->mlx);
}