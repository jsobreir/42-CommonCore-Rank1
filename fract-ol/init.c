/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:22:37 by jsobreir          #+#    #+#             */
/*   Updated: 2024/06/28 12:21:33 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *nbr)
{
	char	*tmp;
	int		intpart;
	int		fracpart;
	int		counter;
	double		ret;
	double	sign;
	
	sign = 1;
	if (*nbr == '-')
	{
		sign = -1;
		nbr++;	
	}
	tmp = nbr;
	while (*nbr != '.')
	{
		nbr++;
	}
	*nbr = '\0';
	intpart = ft_atoi(tmp);
	nbr++;
	counter = 0;
	tmp = nbr;
	while (*nbr)
	{
		nbr++;
		counter++;
	}
	fracpart = ft_atoi(tmp);
	ret = intpart + fracpart / pow(10, counter);
	return (sign * ret);
}

void	init_fractal_dimensions(t_fractal *fractal, char **argv)
{
	if (ft_strcmp(fractal->name, "mandelbrot"))
	{
		fractal->x_max = 2;
		fractal->x_min = -2;
		fractal->y_max = 2;
		fractal->y_min = -2;
	}
	else if (ft_strcmp(fractal->name, "julia"))
	{
		fractal->x_max = 2;
		fractal->x_min = -2;
		fractal->y_max = 1;
		fractal->y_min = -1;
		fractal->z.re = ft_atof(argv[2]);
		printf("argv1 = %f\n", fractal->z.re);
		fractal->z.im = ft_atof(argv[3]);
		printf("argv2 = %f\n", fractal->z.im);
	}
	else
	{
		fractal->x_max = 2;
		fractal->x_min = -2;
		fractal->y_max = 1;
		fractal->y_min = -1;	
	}
}

static void	init_vars(t_fractal	*fractal)
{
	fractal->name = 0;
	fractal->mlx = NULL;
	fractal->mlx_win = NULL;
	fractal->img.img = NULL;
	fractal->x_min = 0.0;
	fractal->x_max = 0.0;
	fractal->y_min = 0.0;
	fractal->y_max = 0.0;
	fractal->scale = 1.0;
	fractal->mouse_pressed = 0;
	fractal->x = 0;
	fractal->y = 0;
	fractal->disp_x = 0;
	fractal->disp_y = 0;
	fractal->z.re = 0.0;
	fractal->z.im = 0.0;
	fractal->z.mod_squared = 0.0;
}
void	fractal_init(t_fractal *fractal)
{
	init_vars(fractal);
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
	{
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
	fractal->scale = 1.0;
}
