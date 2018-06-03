/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 10:49:45 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/06/03 11:40:11 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		(*g_function(int num))(float, float)
{
	if (num == 0)
	{
		return (calc_mandelbrot);
	}
	if (num == 1)
	{
		return (calc_julia);
	}
	if (num == 2)
	{
		return (calc_liam);
	}
	if (num == 3)
	{
		return (calc_liam2);
	}
	return (calc_julibrot);
}

int		error_check(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Available parameters :\n\tjulia\n\tmandelbrot\
	\n\tld\n\textra\n\tjulibrot\n");

		return (-1);
	}
	if (!ft_strcmp(av[1], "mandelbrot"))
		return (0);
	if (!ft_strcmp(av[1], "julia"))
		return (1);
	if (!ft_strcmp(av[1], "ld"))
		return (2);
	if (!ft_strcmp(av[1], "extra"))
		return (3);
	if (!ft_strcmp(av[1], "julibrot"))
		return (3);
	ft_putstr("Non-valid parameter, use : \n\tjulia\n\tmandelbrot\
	\n\tld\n\textra\n\tjulibrot\n");
	return (-1);
}

int		main(int ac, char **av)
{
	if ((g_ptr.val.fractal = error_check(ac, av)) == -1)
		return (0);
	g_ptr.val.iter = 50;
	g_ptr.val.color_changed = 1;
	g_ptr.val.col_fg.r = 205;
	g_ptr.val.col_fg.g = 255;
	g_ptr.val.col_fg.b = 235;
	g_ptr.val.col_bg.r = 20;
	g_ptr.val.col_bg.g = 40;
	g_ptr.val.col_bg.b = 30;
	g_ptr.val.zoom = (WIN_X > WIN_Y) ? WIN_Y / 3 : WIN_X / 3;
	g_ptr.val.mouse_on = 1;
	g_ptr.main = mlx_init();
	g_ptr.window = mlx_new_window(g_ptr.main,
	WIN_X, WIN_Y, "fractol");
	g_ptr.img = mlx_new_image(g_ptr.main, WIN_X, WIN_Y);
	start_draw();
	mlx_put_image_to_window(g_ptr.main, g_ptr.window, g_ptr.img, 0, 0);
	mlx_key_hook(g_ptr.window, key_in, (void *)0);
	mlx_mouse_hook(g_ptr.window, mouse_click, (void *)0);
	mlx_hook(g_ptr.window, 6, 0, mouse_in, (void *)0);
	mlx_expose_hook(g_ptr.window, redraw, (void*)0);
	mlx_loop(g_ptr.main);
	return (0);
}
