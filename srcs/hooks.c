/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 15:17:06 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/12 22:35:24 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	key_hook2(int keycode, t_ms *ms)
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
	if (keycode == 4)
	{
		if (ms->text == 0)
			ms->text = 1;
		else
			ms->text = 0;
	}
	more_options(keycode, ms);
}

int		key_hook(int keycode, t_ms *ms)
{
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
	if (keycode == 89)
		ms->more_color = 1;
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

int		mouse_zoom(int mousecode, int x, int y, t_ms *ms)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, ms);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(ms);
	launch_fractal(ms);
	return (0);
}
