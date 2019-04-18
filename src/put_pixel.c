/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_pixel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 02:12:02 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 12:42:28 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	put_pxl_to_img(t_window *data, int x, int y, int color)
{
	color = mlx_get_color_value(data->mlx, color);
	if (x < WINDOW_W && x > 0 && y < WINDOW_H && y > 0)
		ft_memcpy(data->img_ptr + 4 * (int)WINDOW_W * y + x * 4,
			&color, sizeof(int));
}
