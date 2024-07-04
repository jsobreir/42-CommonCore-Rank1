#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "keys.h"

# define HEIGHT 800
# define WIDTH  800
# define MAX_ITERATIONS 50

typedef struct s_img
{
	void	*img;    // Pointer to image struct
	char	*addr;   // Pointer to the pixels
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_complex
{
	double	re;
	double	im;
	double	mod_squared;
}				t_complex;

typedef struct s_fractal
{
	t_complex	z;
	t_img		img;
	char		*name;
	char		*color_set;
	void		*mlx; // mlx_init()
	void		*mlx_win;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		scale;
	double		disp_x;
	double		disp_y;
	int			x;
	int			y;
	int			mouse_pressed;
	int			j_pressed;
	int			k_pressed;
}				t_fractal;

// Function Prototypes
void	fractal_init(t_fractal *fractal);
void	init_fractal_dimensions(t_fractal *fractal, char **argv);
void	wrong_format(t_fractal *fractal);
void	handle_pixel(t_fractal *fractal, int pix, int piy);
void	put_pixel(int pix, int piy, t_fractal *fractal, int iterations);
void	render_fractol(t_fractal *fractal);
int		clean_exit(t_fractal *fractal);
int		on_key_press(int keycode, t_fractal *fractal);
int		on_key_release(int keycode, t_fractal *fractal);
int		mouse_hooks(int keycode, int x, int y, t_fractal *fractal);
int		fluid_hooks(t_fractal *fractal);
int		mandelbrot(t_fractal *fractal, int pix, int piy);
int		julia(t_fractal *fractal, int pix, int piy);
int		greyscale(int n);
int		rainbow(int n);
int		heatmap(int n);
int		psychadelic(int n);

#endif
