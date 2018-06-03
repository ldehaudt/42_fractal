/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:24:08 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/18 17:29:44 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_col_arr(void)
{
	t_rgb			rgb;
	int				c;
	float			r;

	if (!g_ptr.val.color_changed)
		return ;
	g_ptr.val.color_changed = 0;
	rgb.r = g_ptr.val.col_fg.r;
	rgb.g = g_ptr.val.col_fg.g;
	rgb.b = g_ptr.val.col_fg.b;
	c = 0;
	while (c < g_ptr.val.iter + 10)
	{
		r = (c / ((float)g_ptr.val.iter + 10.0));
		g_arr[c].r = rgb.r * r + ((r == 0) ? 0 : g_ptr.val.col_bg.r * (1 - r));
		g_arr[c].g = rgb.g * r + ((r == 0) ? 0 : g_ptr.val.col_bg.g * (1 - r));
		g_arr[c].b = rgb.b * r + ((r == 0) ? 0 : g_ptr.val.col_bg.b * (1 - r));
		c++;
	}
}

t_rgb	get_color(int val)
{
	t_rgb out;

	make_col_arr();
	out = g_arr[val];
	return (out);
}

void	reverse_color(void)
{
	t_rgb tmp;

	tmp = g_ptr.val.col_fg;
	g_ptr.val.col_fg = g_ptr.val.col_bg;
	g_ptr.val.col_bg = tmp;
}
