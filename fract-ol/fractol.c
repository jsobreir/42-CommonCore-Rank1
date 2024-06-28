/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:13:41 by jsobreir         #+#    #+#             */
/*   Updated: 2024/06/18 14:33:05 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_hooks(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_win, key_hooks, fractal);
	// mlx_hook(fractal->mlx_win, 4, 1L<<2, mouse_pressed, fractal);
    // mlx_hook(fractal->mlx_win, 5, 1L<<3, mouse_released, fractal);
	mlx_mouse_hook(fractal->mlx_win, mouse_hooks, fractal);
}

int main(int argc, char **argv)
{
	t_fractal 	fractal;

	fractal_init(&fractal);
	if (argc < 2)
		return(0);
	fractal.name = argv[1];
	init_fractal_dimensions(&fractal, argv);
	render_fractol(&fractal);
	setup_hooks(&fractal);
	mlx_loop(fractal.mlx);
}
