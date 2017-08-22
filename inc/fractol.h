/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:17:51 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/22 23:08:26 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#                                    include <stdio.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include <mlx.h>
# define WIDTH 1600
# define HEIGHT 1000
# define KEYPRESS 2
# define KEYPRESSMASK 1
# define EXIT 53

typedef struct			s_ms
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*pixels;
	int					s_l;
	int					bpp;
	int					endian;
	int					r;
	int					g;
	int					b;
}						t_ms;

void draw();

#endif
