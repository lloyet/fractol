/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 05:01:32 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 12:41:49 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		mouse_hook(int bouton, int x, int y, t_window *data)
{
	data->x_mouse = x;
	data->y_mouse = y;
	if (bouton == 5 && data->esc_check == 0)
		ft_zoom_in(data);
	if ((bouton == 4 && data->zoom > 25) && data->esc_check == 0)
		ft_zoom_out(data);
	if ((bouton == 5 || bouton == 4) && data->esc_check == 0)
		mouse_reload(data);
	if (data->esc_check == 1)
		fol_switch(data, x, y);
	return (0);
}

void	fol_switch(t_window *data, int x, int y)
{
	if (x > 710 && x < 790 && y > 760 && y < 790)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	if (x > 520 && x < 640 && y > 690 && y < 715)
	{
		initstruct(data);
		data->fractol = 1;
		mouse_reload(data);
	}
	if (x > 520 && x < 620 && y > 720 && y < 745)
	{
		initstruct(data);
		data->fractol = 2;
		mouse_reload(data);
	}
	if (x > 520 && x < 620 && y > 750 && y < 775)
	{
		initstruct(data);
		data->fractol = 3;
		mouse_reload(data);
	}
	fol_switch2(data, x, y);
}

void	fol_switch2(t_window *data, int x, int y)
{
	if (x > 670 && x < 720 && y > 690 && y < 715)
	{
		initstruct(data);
		data->fractol = 4;
		mouse_reload(data);
	}
}

void	mouse_reload(t_window *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	data->img = NULL;
	data->img_ptr = NULL;
	data->img = mlx_new_image(data->mlx, WINDOW_W, WINDOW_H);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp,
		&data->sl, &data->endian);
	data->esc_check = 0;
	if (data->fractol == 1)
		mandel(data);
	if (data->fractol == 2)
		julia(data);
	if (data->fractol == 3)
		tricorn(data);
	if (data->fractol == 4)
		burning(data);
}

int		julia_hook(int x, int y, t_window *data)
{
	if (data->fractol == 2 && data->check_move == 0)
	{
		data->mouse_x = (x - WINDOW_W / 2.0) / WINDOW_W * 2;
		data->mouse_y = (y - WINDOW_H / 2.0) / WINDOW_H * 2;
		mouse_reload(data);
	}
	return (0);
}
