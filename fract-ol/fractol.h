#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "keys.h"

# define HEIGHT 800
# define WIDTH 	800
# define MAX_ITERATIONS 42

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

typedef struct s_complex
{
	double	re;
	double	im;
	double	mod_squared;
}				t_complex;

typedef struct s_fractal
{
	char		*name;
	// MLX
	void		*mlx; // mlx_init()
	void		*mlx_win;
	// Image
	t_img		img;
	t_complex	z;
	int			x;
	int			y;
	int			new_x;
	int			new_y;
	// Fractal specific mathematical limits
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		scale;
	int			mouse_pressed;
	double		disp_x;
	double		disp_y;
}				t_fractal;

// Function Prototypes
void			fractal_init(t_fractal *fractal);
void			handle_pixel(t_fractal *fractal, int pix, int piy);
void			render_fractol(t_fractal *fractal);
// double			map(double unscaled_num, double new_min, double new_max, double old_max, double disp);
// static t_complex 		square_complex(t_complex *z, t_complex *c);
void			put_pixel(int pix, int piy, t_fractal *fractal,int iterations);
int				handle_keypress(int keysym, t_fractal *fractal);
int				ft_strcmp(char *str1, char *str2);
int				key_hook(int keycode, t_fractal *img);
int				close_window(int keycode, t_fractal *img);
int				mouse_hooks(int keycode, int x, int y, t_fractal *fractal);
int				mouse_released(int keycode, int x, int y, t_fractal *fractal);
int 			mouse_pressed(int keycode, int x, int y, t_fractal *fractal);
int				move(int keycode, t_fractal *fractal);
int				key_hooks (int keycode, t_fractal *fractal);
void			init_fractal_dimensions(t_fractal *fractal, char **argv);
int				mandelbrot(t_fractal *fractal, int pix, int piy);
int				julia(t_fractal *fractal, int pix, int piy);


#endif
