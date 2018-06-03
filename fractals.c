/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:23:35 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/18 17:35:59 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		calc_mandelbrot(float x, float y)
{
	int			count;
	t_pos_float	temp;
	t_pos_float	original;
	float		total;

	total = 0;
	count = 0;
	original.x = x;
	original.y = y;
	while (count < g_ptr.val.iter && total < 100)
	{
		temp.x = x;
		temp.y = y;
		x = (temp.x * temp.x) - (temp.y * temp.y) + (original.x);
		y = (temp.x * temp.y) * 2 + (original.y);
		total = x * x + ((g_ptr.val.bones == 0) ? (y * y) : -(y * y));
		count++;
	}
	if (total < 2)
	{
		return (g_ptr.val.iter - 1);
	}
	return (count);
}

int		calc_liam2(float x, float y)
{
	int			count;
	t_pos_float	temp;
	t_pos_float	original;
	float		total;

	total = 0;
	count = 0;
	original.x = x;
	original.y = y;
	while (count < g_ptr.val.iter && total < 100)
	{
		temp.x = x;
		temp.y = y;
		x = (temp.x * temp.x) - (temp.y * temp.y) + (g_ptr.val.mouse.x);
		y = (temp.x * temp.y * temp.y) * 2 + (g_ptr.val.mouse.y);
		total = x * x + ((g_ptr.val.bones == 0) ? (y * y) : -(y * y));
		count++;
	}
	if (total < 2)
	{
		return (g_ptr.val.iter - 1);
	}
	return (count);
}

int		calc_julibrot(float x, float y)
{
	int			count;
	t_pos_float	temp;
	t_pos_float	original;
	float		total;

	total = 0;
	count = 0;
	original.x = x;
	original.y = y;
	while (count < g_ptr.val.iter && total < 100)
	{
		temp.x = x;
		temp.y = y;
		x = (temp.x * temp.x) - (temp.y * temp.y)
		+ (original.x) + g_ptr.val.mouse.x;
		y = (temp.x * temp.y) * 2 + (original.y) + g_ptr.val.mouse.y;
		total = x * x + ((g_ptr.val.bones == 0) ? (y * y) : -(y * y));
		count++;
	}
	if (total < 2)
	{
		return (g_ptr.val.iter - 1);
	}
	return (count);
}

int		calc_julia(float x, float y)
{
	int			count;
	t_pos_float	temp;
	float		total;

	total = 0;
	count = 0;
	while (count < g_ptr.val.iter && total < 100)
	{
		temp.x = x;
		temp.y = y;
		x = (temp.x * temp.x) - (temp.y * temp.y) + (g_ptr.val.mouse.x);
		y = (temp.x * temp.y) * 2 + (g_ptr.val.mouse.y);
		total = (x * x) + ((g_ptr.val.bones == 0) ? (y * y) : -(y * y));
		count++;
	}
	if (total < 2)
	{
		return (g_ptr.val.iter - 1);
	}
	return (count);
}

int		calc_liam(float x, float y)
{
	int			count;
	t_pos_float	temp;
	float		total;

	total = 0;
	count = 0;
	while (count < g_ptr.val.iter && total < 100)
	{
		temp.x = x;
		temp.y = y;
		x = (temp.x * temp.x) - (temp.y * temp.y) + (g_ptr.val.mouse.x);
		y = (temp.x * temp.y) * 3 + (g_ptr.val.mouse.y);
		total = x * x + ((g_ptr.val.bones == 0) ? (y * y) : -(y * y));
		count++;
	}
	if (total < 2)
	{
		return (g_ptr.val.iter - 1);
	}
	return (count);
}
