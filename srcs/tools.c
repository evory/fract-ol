/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:00:22 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/12 22:35:25 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		ft_init_mlx(t_ms *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WIDTH, WIDTH, "fractol");
	ms->img = mlx_new_image(ms->mlx, WIDTH, WIDTH);
	ms->pixels = mlx_get_data_addr(ms->img, &ms->bpp, &ms->s_l, &ms->endian);
	return (0);
}

void	put_pxl_to_img(t_ms *ms, int x, int y, int color)
{
	if (ms->x < WIDTH && ms->y < WIDTH)
	{
		color = mlx_get_color_value(ms->mlx, color);
		ft_memcpy(ms->pixels + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	launch_fractal(t_ms *ms)
{
	if (ms->name == 1)
		launch_julia(ms);
	if (ms->name == 2)
		launch_mandelbrot(ms);
	if (ms->name == 3)
		launch_burningship(ms);
}

void	choose_launcher(t_ms *ms)
{
	if (ms->name == 1)
		init_julia(ms);
	if (ms->name == 2)
		init_mandelbrot(ms);
	if (ms->name == 3)
		init_burningship(ms);
	launch_fractal(ms);
}

void	text(t_ms *ms)
{
	char	*str;

	str = "Usage : [1][2][3] : Choose fractal";
	mlx_string_put(ms->mlx, ms->win, 10, 10, 0xFFFFFF, str);
	str = "[1][2][3][4][5] NUMPAD : Have fun";
	mlx_string_put(ms->mlx, ms->win, 90, 35, 0xFFFFFF, str);
	str = "[mouse click] : Zoom in - Zoom out";
	mlx_string_put(ms->mlx, ms->win, 90, 60, 0xFFFFFF, str);
	str = "[M] : Open new window";
	mlx_string_put(ms->mlx, ms->win, 90, 85, 0xFFFFFF, str);
	str = "[space bar] : Modify Julia with your mouse";
	mlx_string_put(ms->mlx, ms->win, 90, 110, 0xFFFFFF, str);
	str = "[+] [-] : Change level of details";
	mlx_string_put(ms->mlx, ms->win, 90, 135, 0xFFFFFF, str);
	str = "[R] : Reset fractal";
	mlx_string_put(ms->mlx, ms->win, 90, 160, 0xFFFFFF, str);
	str = "[H] : Hide text";
	mlx_string_put(ms->mlx, ms->win, 90, 755, 0xFFFFFF, str);
}
