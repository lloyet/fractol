/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tool.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 00:52:41 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 12:42:56 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		key_hook(int keycode, t_window *data)
{
	if (keycode == ESC_KEY)
		destroy_fractol(data);
	if (keycode == LOCK)
		lock_key(data);
	if (keycode == SPACE_KEY && data->esc_check == 0)
		legend(data);
	else if (keycode == SPACE_KEY && data->esc_check == 1)
		clear_legend(data);
	(keycode == PLUS_KEY) ?
		data->it_max = data->it_max + 10 : data->it_max;
	(keycode == MINUS_KEY && data->it_max > 10) ?
		data->it_max = data->it_max - 10 : data->it_max;
	if (keycode == 8)
		color(data, data->colorvalue++);
	if (keycode == PLUS_KEY || keycode == MINUS_KEY || keycode == 8)
		mouse_reload(data);
	return (0);
}

int		expose_hook(t_window *data)
{
	if (data->fractol == 1)
		mandel(data);
	if (data->fractol == 2)
		julia(data);
	if (data->fractol == 3)
		tricorn(data);
	if (data->fractol == 4)
		burning(data);
	return (0);
}

void	destroy_fractol(t_window *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	exit(1);
}

void	lock_key(t_window *data)
{
	if (data->check_move == 0)
		data->check_move = 1;
	else
		data->check_move = 0;
}
