/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:00:22 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/08 11:09:09 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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

void	check_name(t_ms *ms, char const *name)
{
	if (ft_strcmp(name, "julia") == 0)
		ms->name = 1;
	else if (ft_strcmp(name, "mandelbrot") == 0)
		ms->name = 2;
	else if (ft_strcmp(name, "burningship") == 0)
		ms->name = 3;
	else
	{
		ft_putendl("usage : ./fractol [julia, mandelbrot or burningship]");
		exit(EXIT_SUCCESS);
	}
}
