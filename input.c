/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:22:54 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/18 17:23:12 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_cont_cont(int key)
{
	if (key == 32)
		g_ptr.val.col_bg.r += (g_ptr.val.col_bg.r <= 245) ? 10 : 0;
	else if (key == 38)
		g_ptr.val.col_bg.g += (g_ptr.val.col_bg.g <= 245) ? 10 : 0;
	else if (key == 46)
		g_ptr.val.col_bg.b += (g_ptr.val.col_bg.b <= 245) ? 10 : 0;
	else if (key == 0)
		g_ptr.val.iter += ((g_ptr.val.iter > 20) ? -5 : 0);
	else if (key == 2)
		g_ptr.val.iter += ((g_ptr.val.iter < 400) ? 5 : 0);
	else if (key == 1)
		reverse_color();
}

void	key_cont(int key)
{
	g_ptr.val.color_changed = 1;
	if (key == 15)
		g_ptr.val.col_fg.r -= (g_ptr.val.col_fg.r >= 10) ? 10 : 0;
	else if (key == 3)
		g_ptr.val.col_fg.g -= (g_ptr.val.col_fg.g >= 10) ? 10 : 0;
	else if (key == 9)
		g_ptr.val.col_fg.b -= (g_ptr.val.col_fg.b >= 10) ? 10 : 0;
	else if (key == 17)
		g_ptr.val.col_fg.r += (g_ptr.val.col_fg.r <= 245) ? 10 : 0;
	else if (key == 5)
		g_ptr.val.col_fg.g += (g_ptr.val.col_fg.g <= 245) ? 10 : 0;
	else if (key == 11)
		g_ptr.val.col_fg.b += (g_ptr.val.col_fg.b <= 245) ? 10 : 0;
	else if (key == 16)
		g_ptr.val.col_bg.r -= (g_ptr.val.col_bg.r >= 10) ? 10 : 0;
	else if (key == 4)
		g_ptr.val.col_bg.g -= (g_ptr.val.col_bg.g >= 10) ? 10 : 0;
	else if (key == 45)
		g_ptr.val.col_bg.b -= (g_ptr.val.col_bg.b >= 10) ? 10 : 0;
	else
		key_cont_cont(key);
}

int		key_in(int key, void *param)
{
	param = 0;
	if (key == 53)
		exit(0);
	else if (key == 49)
		g_ptr.val.mouse_on = (g_ptr.val.mouse_on == 0) ? 1 : 0;
	else if (key == 123 || key == 124)
		g_ptr.val.offset.x += 200 / g_ptr.val.zoom * ((key == 123)
		/ g_ptr.val.zoom ? 1 : -1);
	else if (key == 126 || key == 125)
		g_ptr.val.offset.y += 200 / g_ptr.val.zoom * ((key == 125)
		/ g_ptr.val.zoom ? -1 : 1);
	else if (key == 14)
		g_ptr.val.fractal += ((g_ptr.val.fractal < 4) ? 1 : 0);
	else if (key == 12)
		g_ptr.val.fractal += ((g_ptr.val.fractal > 0) ? -1 : 0);
	else if (key == 13)
		g_ptr.val.bones = 1 - g_ptr.val.bones;
	else
		key_cont(key);
	redraw(NULL);
	return (0);
}

int		mouse_click(int button, int x, int y, void *param)
{
	param = 0;
	x = y;
	if (button == 5)
	{
		g_ptr.val.offset.x -= (g_ptr.val.m.x) * 168.5 / g_ptr.val.zoom;
		g_ptr.val.offset.y += (g_ptr.val.m.y) * 168.5 / g_ptr.val.zoom;
		g_ptr.val.zoom *= 1.2;
		redraw(NULL);
	}
	if (button == 4)
	{
		g_ptr.val.offset.x += (g_ptr.val.m.x) * 168.5 / g_ptr.val.zoom;
		g_ptr.val.offset.y -= (g_ptr.val.m.y) * 168.5 / g_ptr.val.zoom;
		g_ptr.val.zoom *= 0.8333;
		redraw(NULL);
	}
	return (0);
}

int		mouse_in(int x, int y, void *param)
{
	param = 0;
	g_ptr.val.m.x = (x - WIN_X / 2) * 0.001f;
	g_ptr.val.m.y = (WIN_Y / 2 - y) * 0.001f;
	if (g_ptr.val.mouse_on)
	{
		g_ptr.val.mouse.x = (x - WIN_X / 2) * 0.001f;
		g_ptr.val.mouse.y = (WIN_Y / 2 - y) * 0.001f;
		redraw(NULL);
	}
	return (0);
}
