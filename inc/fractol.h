/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:17:51 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/30 23:10:38 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#                              include <stdio.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include <mlx.h>
# include <pthread.h>
# define WIDTH 799
# define KEYPRESS 2
# define KEYPRESSMASK 1
# define EXIT 53

typedef struct	s_ms
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixels;
	int			s_l;
	int			bpp;
	int			endian;

	int			color;
	int			mouse;
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

void			check_name(t_ms *ms, char const *name);
void			init_fractal(t_ms *ms);
void			init_julia(t_ms *ms);
void			init_mandelbrot(t_ms *ms);
void			init_choose(t_ms *ms);
void			launch_julia(t_ms *ms);
void			launch_mandelbrot(t_ms *ms);
void			launch_choose(t_ms *ms);
void			put_pxl_to_img(t_ms *ms, int x, int y, int color);
int				key_hook(int keycode, t_ms *ms);
int				ft_close(void);

#endif
