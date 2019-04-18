/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   legend.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 05:21:16 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 12:39:43 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	legend(t_window *data)
{
	int x;
	int y;
	int x_max;
	int y_max;

	x_max = 800;
	y_max = 800;
	y = 640;
	while (y < y_max)
	{
		x = 500;
		while (x < x_max)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, 0x123456);
			x++;
		}
		y++;
	}
	data->esc_check = 1;
	data->check_move = 1;
	write_in_leg(data);
}

void	write_in_leg(t_window *data)
{
	mlx_string_put(data->mlx, data->win, 520, 660, 0x000000, "Fractales :");
	mlx_string_put(data->mlx, data->win, 520, 690, 0x000000, "Mandelbrot");
	mlx_string_put(data->mlx, data->win, 520, 720, 0x000000, "Julia");
	mlx_string_put(data->mlx, data->win, 520, 750, 0x000000, "Tricorn");
	mlx_string_put(data->mlx, data->win, 670, 690, 0x000000, "Burningship");
	mlx_string_put(data->mlx, data->win, 710, 760, 0x000000, "QUITTER");
}

void	clear_legend(t_window *data)
{
	data->esc_check = 0;
	data->check_move = 0;
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
