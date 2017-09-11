/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:17:51 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/11 20:36:05 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "../lib/libft/libft.h"
# include <mlx.h>
# include <pthread.h>
# define WIDTH 799
# define KEYPRESS 2
# define KEYPRESSMASK 1
# define EXIT 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef struct	s_ms
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixels;
	int			s_l;
	int			bpp;
	int			endian;
	int			name;
	int			color;
	int			mouse;
	int			j_mouse;
	int			text;
	int			more_color;
	double		zoom;
	double		it_max;
	double		x1;
	double		y1;
	double		x;
	double		y;
	double		y_max;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		it;
	double		x2;
	double		y2;
	double		tmp;
}				t_ms;

int				ft_init_mlx(t_ms *ms);
void			init_julia(t_ms *ms);
void			init_mandelbrot(t_ms *ms);
void			init_burningship(t_ms *ms);
void			launch_julia(t_ms *ms);
void			launch_mandelbrot(t_ms *ms);
void			launch_burningship(t_ms *ms);
void			put_pxl_to_img(t_ms *ms, int x, int y, int color);
int				key_hook(int keycode, t_ms *ms);
void			launch_fractal(t_ms *ms);
void			choose_launcher(t_ms *ms);
int				mouse_zoom(int mousecode, int x, int y, t_ms *ms);
int				mouse_julia(int x, int y, t_ms *ms);
int				ft_init_mlx(t_ms *ms);
void			more_options(int keycode, t_ms *ms);
void			text(t_ms *ms);
#endif
