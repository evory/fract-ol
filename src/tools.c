/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:00:22 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/29 17:43:17 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		key_hook(int keycode, t_ms *ms)
{
	if (keycode == EXIT)
		exit(EXIT_SUCCESS);
	else
		return (0);
	mlx_destroy_image(ms->mlx, ms->img);
	return (0);
}

void	check_name(t_ms *ms, char const *name)
{
	if (ft_strcmp(name, "julia") == 0)
	{
		init_julia(ms);
		launch_julia(ms);
	}
	else if (ft_strcmp(name, "mandelbrot") == 0)
	{
		init_mandelbrot(ms);
		launch_mandelbrot(ms);
	}
	else if (ft_strcmp(name, "choose") == 0)
	{
		init_choose(ms);
		launch_choose(ms);
	}
	else
	{
		ft_putendl("usage : ./fractol [julia, mandelbrot or choose]");
		exit(EXIT_SUCCESS);
	}
}
