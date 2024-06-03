/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:13:41 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/02 16:48:53 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_fractal 	fractal;
	// t_img		img;
	
	fractal_init(&fractal);
	fractal.img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	render_fractol(&fractal);
	mlx_hook(fractal.mlx_win, 2, 1L<<0, close, &fractal);
	mlx_loop(fractal.mlx);
}