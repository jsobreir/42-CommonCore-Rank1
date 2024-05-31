/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:49:00 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/31 17:53:20 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(fractal->mlx, fractal->mlx_win);
        fractal->mlx_win = NULL;
		free(fractal->img.img);
		free(fractal->mlx_win);
		free(fractal->mlx);
    }
    return (0);
}