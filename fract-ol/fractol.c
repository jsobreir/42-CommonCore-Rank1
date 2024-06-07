/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:13:41 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/07 19:29:50 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void help_msg(int n)
{
	if (n == 0)
		printf("Error! Please specify the fractol name!");
}

int main(int argc, char **argv)
{
	t_fractal 	fractal;
	  ft_memset(&fractal, 0, sizeof(t_fractal));
	fractal.name = argv[1];
	if (argc < 2)
		return(help_msg(argc), 0);
	fractal_init(&fractal);
	render_fractol(&fractal);
	mlx_hook(fractal.mlx_win, 2, 1L<<0, close_window, &fractal); // Close window
	mlx_mouse_hook(fractal.mlx_win, mouse_hook, &fractal);
	mlx_loop(fractal.mlx);
}
