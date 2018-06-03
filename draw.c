/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:23:56 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/18 17:31:21 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_point(int x, int y, t_rgb color)
{
	char	*col;
	int		bpp;
	int		size_line;
	int		endian;

	col = mlx_get_data_addr(g_ptr.img, &bpp, &size_line, &endian);
	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y)
		return ;
	col[(x * 4 + y * 4 * WIN_X)] = (unsigned char)color.b;
	col[(x * 4 + y * 4 * WIN_X) + 1] = (unsigned char)color.g;
	col[(x * 4 + y * 4 * WIN_X) + 2] = (unsigned char)color.r;
}

int		redraw(void *p)
{
	p = NULL;
	mlx_destroy_image(g_ptr.main, g_ptr.img);
	g_ptr.img = mlx_new_image(g_ptr.main, WIN_X, WIN_Y);
	start_draw();
	mlx_put_image_to_window(g_ptr.main, g_ptr.window, g_ptr.img, 0, 0);
	return (0);
}

void	*draw_fractal(void *x_start)
{
	int x;
	int i;
	int val;

	i = 0;
	while (i < WIN_Y)
	{
		x = *((int *)x_start);
		while (x < WIN_X)
		{
			val = g_function(g_ptr.val.fractal)((x - WIN_X / 2) /
			g_ptr.val.zoom - g_ptr.val.offset.x, (WIN_Y / 2 - i)
			/ g_ptr.val.zoom + g_ptr.val.offset.y);
			draw_point(x, i, get_color(val));
			x += 4;
		}
		i++;
	}
	return (NULL);
}

void	start_draw(void)
{
	int			i[4];
	pthread_t	id0;
	pthread_t	id1;
	pthread_t	id2;
	pthread_t	id3;

	i[0] = 0;
	i[1] = 1;
	i[2] = 2;
	i[3] = 3;
	make_col_arr();
	pthread_create(&id0, NULL, draw_fractal, (void *)(&i[0]));
	pthread_create(&id1, NULL, draw_fractal, (void *)(&i[1]));
	pthread_create(&id2, NULL, draw_fractal, (void *)(&i[2]));
	pthread_create(&id3, NULL, draw_fractal, (void *)(&i[3]));
	pthread_join(id0, NULL);
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);
	pthread_join(id3, NULL);
}
