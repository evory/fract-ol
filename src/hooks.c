/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 15:17:06 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/08 11:50:38 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	more_option2(int keycode, t_ms *ms)
{
	printf("%f\n", ms->it_max);
	if (keycode == 85)
	{
		if(ms->name < 3)
		ms->name++;
		else
			ms->name -= 2;
			ms->color += 500000;
	}
	if (keycode == 86)
	{
		if(ms->name < 3)
			ms->name++;
		else
			ms->name --;
		ms->color += 500000;
	}
	launch_fractal(ms);
}

void	more_option(int keycode, t_ms *ms)
{
	if (keycode == 46)
	{
		if(ms->name < 3)
			ms->name++;
		else
			ms->name -= 2;
		ft_init_mlx(ms);
		choose_launcher(ms);
		mlx_hook(ms->win, 2, 1, mouse_julia, ms);
		mlx_hook(ms->win, 2, 1, key_hook, ms);
		mlx_mouse_hook(ms->win, mouse_hook, ms);
		mlx_loop(ms->mlx);
	}
	if (keycode == 83)
		ms->color = 898888;
	if (keycode == 84)
	{
		ms->color += 500000;
	}
	more_option2(keycode, ms);
}

void		key_hook2(int keycode, t_ms *ms)
{
	if (keycode == 18)
	{
		ms->name = 1;
		choose_launcher(ms);
	}
	if (keycode == 19)
	{
		ms->name = 2;
		choose_launcher(ms);
	}
	if (keycode == 20)
	{
		ms->name = 3;
		choose_launcher(ms);
	}
	if (keycode == 15)
		choose_launcher(ms);
	more_option(keycode, ms);
}

int		key_hook(int keycode, t_ms *ms)
{
	printf("%d\n", keycode);
	if (keycode == EXIT)
		exit(EXIT_SUCCESS);
	if (keycode == UP)
		ms->y1 -= 30 / ms->zoom;
	if (keycode == DOWN)
		ms->y1 += 30 / ms->zoom;
	if (keycode == LEFT)
		ms->x1 -= 30 / ms->zoom;
	if (keycode == RIGHT)
		ms->x1 += 30 / ms->zoom;
	if (keycode == 69)
		ms->it_max++;
	if (keycode == 78)
		ms->it_max--;
	key_hook2(keycode, ms);
	return (0);
}

void	ft_zoom(int x, int y, t_ms *ms)
{
	ms->x2 = x;
	ms->y2 = y;
	ms->x1 = (x / ms->zoom + ms->x1) - ((ms->zoom * 1.3) / 2);
	ms->x1 += ((ms->zoom * 1.3) / 2) - (x / (ms->zoom * 1.3));
	ms->y1 = (y / ms->zoom + ms->y1) - ((ms->zoom * 1.3) / 2);
	ms->y1 += ((ms->zoom * 1.3) / 2) - (y / (ms->zoom * 1.3));
	ms->zoom *= 1.3;
	ms->it_max++;
}

void	ft_dezoom(t_ms *ms)
{
	ms->x1 = (ms->x2 / ms->zoom + ms->x1) - ((ms->zoom / 1.3) / 2);
	ms->x1 += ((ms->zoom / 1.3) / 2) - (ms->x2 / (ms->zoom / 1.3));
	ms->y1 = (ms->y2 / ms->zoom + ms->y1) - ((ms->zoom / 1.3) / 2);
	ms->y1 += ((ms->zoom / 1.3) / 2) - (ms->y2 / (ms->zoom / 1.3));
	ms->zoom /= 1.3;
	ms->it_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_ms *ms)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, ms);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(ms);
	launch_fractal(ms);
	return (0);
}
