/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zoom.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 02:08:40 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 12:44:02 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_zoom_in(t_window *data)
{
	data->zoom *= 2.0;
	data->y_move *= 2.0;
	data->x_move *= 2.0;
	data->y_move += (data->y_mouse - WINDOW_H / 2.0);
	data->x_move += (data->x_mouse - WINDOW_W / 2.0);
}

void	ft_zoom_out(t_window *data)
{
	data->zoom /= 2.0;
	data->x_move -= (data->x_mouse - WINDOW_W / 2.0);
	data->y_move -= (data->y_mouse - WINDOW_H / 2.0);
	data->x_move /= 2.0;
	data->y_move /= 2.0;
}
