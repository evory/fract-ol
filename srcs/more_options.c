/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:12:15 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/11 19:12:08 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	more_options2(int keycode, t_ms *ms)
{
	if (keycode == 85)
	{
		if (ms->name < 3)
			ms->name++;
		else
			ms->name -= 2;
		ms->color += 500000;
	}
	if (keycode == 86)
	{
		if (ms->name < 3)
			ms->name++;
		else
			ms->name--;
		ms->color += 500000;
	}
	if (keycode == 49)
	{
		if (ms->j_mouse == 1)
			ms->j_mouse = 0;
		else
			ms->j_mouse = 1;
	}
	launch_fractal(ms);
}

void	more_options(int keycode, t_ms *ms)
{
	if (keycode == 46)
	{
		if (ms->name < 3)
			ms->name++;
		else
			ms->name -= 2;
		ft_init_mlx(ms);
		choose_launcher(ms);
		mlx_hook(ms->win, 6, 1L << 6, mouse_julia, ms);
		mlx_hook(ms->win, 2, 1, key_hook, ms);
		mlx_mouse_hook(ms->win, mouse_zoom, ms);
		mlx_loop(ms->mlx);
	}
	if (keycode == 83)
		ms->color = 898888;
	if (keycode == 84)
	{
		ms->color += 500000;
	}
	if (keycode == 87)
		ms->color = 15;
	more_options2(keycode, ms);
}
