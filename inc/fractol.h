/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 02:04:03 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 12:37:06 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# define FRACT "mandelbrot, julia, tricorn, burningship"
# define USAGE "Usage : " FRACT
# define WINDOW_W 800
# define WINDOW_H 800
# define ESC_KEY 53
# define SPACE_KEY 49
# define PLUS_KEY 69
# define MINUS_KEY 78
# define LOCK 35
# define MANDEL 1
# define JULIA 2
# define TRICORN 3
# define BS 4

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_ptr;
	char		*title;
	int			esc_check;
	int			check_move;
	int			bpp;
	int			endian;
	int			sl;
	int			color;
	int			*color_tab;
	int			colorvalue;
	int			fractol;
	int			it_max;
	int			col;
	int			col_max;
	int			row;
	int			it;
	int			x_mouse;
	int			y_mouse;
	double		y;
	double		x;
	double		zoom;
	double		c_re;
	double		c_im;
	double		x_new;
	double		x_move;
	double		y_move;
	double		mouse_x;
	double		mouse_y;
}				t_window;

/*
** In main.c
*/
void			initfractol(void);
void			initstruct(t_window *data);
/*
** In julia.c
*/
void			*julia2(void *tab);
void			julia(t_window *data);
void			juliacalc(t_window *data);
void			juliacalc2(t_window *data);
/*
** In mandel.c
*/
void			*mandel2(void *tab);
void			mandel(t_window *data);
void			mandelcalc(t_window *data);
void			mandelcalc2(t_window *data);
/*
** In tricorn.c
*/
void			*tricorn2(void *tab);
void			tricorncalc(t_window *data);
void			tricorncalc2(t_window *data);
void			tricorn(t_window *data);
/*
** In urnings.c
*/
void			*bs2(void *tab);
void			bscalc(t_window *data);
void			bscalc2(t_window *data);
void			burning(t_window *data);
/*
** In tool.c
*/
int				key_hook(int keycode, t_window *data);
int				expose_hook(t_window *data);
void			destroy_fractol(t_window *data);
void			lock_key(t_window *data);
/*
** In zoom.c
*/
void			ft_zoom_in(t_window *data);
void			ft_zoom_out(t_window *data);
/*
** In legend.c
*/
void			legend(t_window *data);
void			write_in_leg(t_window *data);
void			clear_legend(t_window *data);
/*
** In mouse.c
*/
int				mouse_hook(int bouton, int x, int y, t_window *data);
void			mouse_reload(t_window *data);
void			fol_switch(t_window *data, int x, int y);
int				julia_hook(int x, int y, t_window *data);
void			fol_switch2(t_window *data, int x, int y);
/*
** In put_pixel.c
*/
void			put_pxl_to_img(t_window *data, int x, int y, int color);
/*
** In color.c
*/
void			color(t_window *data, int i);
#endif
