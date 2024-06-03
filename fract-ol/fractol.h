#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define HEIGHT 800
# define WIDTH 	800
# define MAX_ITERATIONS 512

#define RED           0xFF0000
#define GREEN         0x00FF00
#define BLUE          0x0000FF
#define WHITE		  0xFFFFFF
#define BLACK		  0x000000
#define YELLOW        0xFFFF00
#define CYAN          0x00FFFF
#define MAGENTA       0xFF00FF
#define ORANGE        0xFFA500
#define PINK          0xFFC0CB
#define PURPLE        0x800080
#define LIME          0x00FF00
#define TEAL          0x008080
#define VIOLET        0xEE82EE
#define INDIGO        0x4B0082

// Psychedelic colors
#define PSYCHEDELIC1  0xFF00FF // Bright Magenta
#define PSYCHEDELIC2  0x00FF00 // Bright Green
#define PSYCHEDELIC3  0x0000FF // Bright Blue
#define PSYCHEDELIC4  0xFF00FF // Bright Magenta
#define PSYCHEDELIC5  0xFFFF00 // Bright Yellow
#define PSYCHEDELIC6  0xFF69B4 // Hot Pink
#define PSYCHEDELIC7  0xFF4500 // Orange Red
#define PSYCHEDELIC8  0x8A2BE2 // Blue Violet

/* IMAGE
	Pixels vuffer values from mlx_get_data_addr()
*/
typedef struct s_img {
	void	*img; 	// Pointer to image struct
	char	*addr; 	// Pointer to the pixels
	int		bpp;
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
	// Fractal specific mathematical limits
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}				t_fractal;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;


// Function Prototypes
void	fractal_init(t_fractal *fractal);

#endif