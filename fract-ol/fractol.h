#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "mlx_linux/mlx.h"
#include "../libft/libft.h"
#include <X11/keysym.h>
#include <X11/X.h>

# define HEIGHT 800
# define WIDTH 	800
/* IMAGE
	Pixels vuffer values from mlx_get_data_addr()
*/
typedef struct s_img {
	void	*img; 	// Pointer to image struct
	char	*addr; 	// Pointer to the pixels
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

/* Fractal ID
 ~ MLX
 ~ Image
 ~ Hooks Value
*/
typedef struct s_fractal
{
	char	*name;
	// MLX
	void	*mlx; // mlx_init()
	void	*mlx_win;
	// Image
	t_img	img;
}				t_fractal;

// Function Prototypes
void	fractal_init(t_fractal *fractal);

#endif