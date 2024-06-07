/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:22:37 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/04 21:03:02 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	* INIT
	* ~mlx
	* ~listening events
	* ~hooks data
*/
// static void	malloc_error(void)
// {
// 	write(2, "Problems with Malloc", 20);
// 	exit(EXIT_FAILURE);
// }

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL) {
    	fprintf(stderr, "Error initializing MiniLibX\n");
    	exit(EXIT_FAILURE);
	}
	fractal->mlx_win = mlx_new_window(fractal->mlx, 800, 800, "Fractol");
	if (NULL == fractal->mlx_win)
	{
		fprintf(stderr, "Error creating window\n");
    	exit(EXIT_FAILURE);
	}
	fractal->img.img = mlx_new_image(fractal->mlx, HEIGHT, WIDTH);
	if (fractal->img.img == NULL)
	{
		fprintf(stderr, "Error creating image\n");
    	exit(EXIT_FAILURE);
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
    if (fractal->img.addr == NULL) {
        fprintf(stderr, "Error getting data address\n");
        mlx_destroy_image(fractal->mlx, fractal->img.img); // Clean up image
        mlx_destroy_window(fractal->mlx, fractal->mlx_win); // Clean up window
        exit(EXIT_FAILURE);
    }
}
