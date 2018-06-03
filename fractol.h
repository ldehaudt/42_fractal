/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldehaudt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:25:19 by ldehaudt          #+#    #+#             */
/*   Updated: 2018/05/18 17:36:55 by ldehaudt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_X 1440
# define WIN_Y 1440

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_pos_float
{
	float	x;
	float	y;
}				t_pos_float;

typedef struct	s_rgb
{
	float r;
	float g;
	float b;
}				t_rgb;

typedef struct	s_img_values
{
	t_rgb		col_fg;
	t_rgb		col_bg;
	int			color_changed;
	t_pos_float offset;
	t_pos_float mouse;
	t_pos_float m;
	int			mouse_on;
	float		zoom;
	int			fractal;
	int			iter;
	int			bones;
}				t_img_values;

typedef struct	s_lib_ptrs
{
	void			*main;
	void			*window;
	void			*img;
	t_img_values	val;
}				t_lib_ptrs;

int				mouse_in(int x, int y, void *param);
int				mouse_click(int button, int x, int y, void *param);
int				key_in(int key, void *param);
void			key_cont(int key);
void			key_cont_cont(int key);
int				calc_liam2(float x, float y);
int				calc_mandelbrot(float x, float y);
int				calc_julibrot(float x, float y);
int				calc_julia(float x, float y);
int				calc_liam(float x, float y);
void			reverse_color(void);
t_rgb			get_color(int val);
void			make_col_arr(void);
void			start_draw(void);
void			*draw_fractal(void *x_start);
void			draw_point(int x, int y, t_rgb color);
int				redraw(void *p);
void			start_draw(void);
int				(*g_function(int num))(float, float);

t_lib_ptrs	g_ptr;
t_rgb		g_arr[410];

#endif
