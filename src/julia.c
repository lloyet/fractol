/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 02:08:55 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 12:39:10 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <pthread.h>

void	*julia2(void *tab)
{
	int			w;
	t_window	*data;

	data = (t_window*)tab;
	w = data->col;
	data->row = 0;
	while (data->row < WINDOW_H)
	{
		data->col = w;
		while (data->col < data->col_max)
		{
			juliacalc(data);
			while (data->x * data->x + data->y * data->y <= 4
				&& data->it < data->it_max)
				juliacalc2(data);
			put_pxl_to_img(data, data->col, data->row, ((int)(data->color *
				((double)data->it / data->it_max)) & data->color) +
				((int)(0xFF00 * ((double)data->it / data->it_max)) & 0xFF00));
			data->col++;
		}
		data->row++;
	}
	return (tab);
}

void	juliacalc(t_window *data)
{
	data->c_re = data->mouse_x;
	data->c_im = data->mouse_y;
	data->x = ((data->col + (WINDOW_W / -2.0 + data->x_move)) /
			data->zoom) * 400.0 / WINDOW_W;
	data->y = ((data->row + (WINDOW_H / -2.0 + data->y_move)) /
			data->zoom) * 400.0 / WINDOW_W;
	data->it = 0;
}

void	juliacalc2(t_window *data)
{
	data->x_new = (data->x * data->x - data->y * data->y + data->c_re);
	data->y = (2 * data->x * data->y + data->c_im);
	data->x = data->x_new;
	data->it++;
}

void	julia(t_window *data)
{
	t_window	tab[8];
	pthread_t	t[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_window));
		tab[i].col = 100 * i;
		tab[i].col_max = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&t[i - 1], NULL, julia2, &tab[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
