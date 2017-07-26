/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:17:51 by bbrandt           #+#    #+#             */
/*   Updated: 2017/07/26 17:29:56 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"
# include <mlx.h>
# define WIDTH 2500
# define HEIGHT 1300
# define KEYPRESS 2
# define KEYPRESSMASK 1
# define EXIT 53

typedef struct	s_ms
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				s_l;
	int				bpp;
	int				endian;
}				t_ms;

#endif
