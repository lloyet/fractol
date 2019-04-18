/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 02:04:12 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 12:40:35 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	initmlx(t_window *data, int fractol)
{
	data->fractol = fractol;
	if ((data->mlx = mlx_init()) == NULL)
		exit(0);
	if ((data->win = mlx_new_window(data->mlx, WINDOW_W, WINDOW_H,
		"Fractol")) == NULL)
		exit(0);
	data->img = mlx_new_image(data->mlx, WINDOW_W, WINDOW_H);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp,
		&data->sl, &data->endian);
	initstruct(data);
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_hook(data->win, 6, 1L < 6, julia_hook, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_loop(data->mlx);
	exit(1);
}

void	initstruct(t_window *data)
{
	data->col = 0;
	data->col_max = 100;
	data->row = 0;
	data->zoom = 100;
	data->x_move = 0;
	data->y_move = 0;
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->colorvalue = 1;
	data->esc_check = 0;
	data->check_move = 0;
	data->it_max = 160;
	data->color = 0x00aaff;
}

void	checkarg(char *arg, t_window *data)
{
	if (ft_strcmp(arg, "mandelbrot") == 0)
		initmlx(data, MANDEL);
	if (ft_strcmp(arg, "julia") == 0)
		initmlx(data, JULIA);
	if (ft_strcmp(arg, "tricorn") == 0)
		initmlx(data, TRICORN);
	if (ft_strcmp(arg, "burningship") == 0)
		initmlx(data, BS);
	ft_putendl(USAGE);
}

int		main(int ac, char **av)
{
	t_window *data;

	data = (t_window *)malloc(sizeof(t_window));
	if (ac != 2)
		ft_putendl(USAGE);
	else
		checkarg(av[1], data);
	return (0);
}
