/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:17:51 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/11 16:46:16 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#include <stdio.h>
# include "../lib/libft/libft.h"
# include <mlx.h>
# define WIDTH 2400
# define HEIGHT 1400
# define KEYPRESS 2
# define KEYPRESSMASK 1
# define EXIT 53

typedef struct			s_ms
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					s_l;
	int					bpp;
	int					endian;
	const char			*name;
	struct s_fractal	*julia;
	struct s_fractal	*mandelbrot;
	struct s_fractal	*choose;
}						t_ms;

typedef struct			s_fractal
{
	long double			x1;
	long double			x2;
	long double			y1;
	long double			y2;
	long double			zr;
	long double			zi;
	long double			cr;
	long double			ci;
}						t_fractal;

void	ft_pixel_put(t_ms *ms, int x, int y);
int		loop(t_ms *ms);
t_ms	init_env(t_ms *ms, char const *name);
#endif
