/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:36:48 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/12 22:35:25 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	julia(t_ms *ms)
{
	ms->z_r = ms->x / ms->zoom + ms->x1;
	ms->z_i = ms->y / ms->zoom + ms->y1;
	ms->it = 0;
	while (ms->z_r * ms->z_r + ms->z_i
		* ms->z_i < 4 && ms->it < ms->it_max)
	{
		ms->tmp = ms->z_r;
		ms->z_r = ms->z_r * ms->z_r -
		ms->z_i * ms->z_i - 0.8 + (ms->c_r / WIDTH);
		ms->z_i = 2 * ms->z_i * ms->tmp + ms->c_i / WIDTH;
		ms->it++;
	}
	if (ms->it == ms->it_max)
		put_pxl_to_img(ms, ms->x, ms->y, 0);
	else
		put_pxl_to_img(ms, ms->x, ms->y, (ms->color * ms->it));
}

void	*julia_loop(void *tab_ms)
{
	double	tmp;
	t_ms	*ms;

	ms = tab_ms;
	tmp = ms->y;
	while (ms->x < WIDTH)
	{
		ms->y = tmp;
		while (ms->y < ms->y_max)
		{
			julia(ms);
			ms->y++;
		}
		ms->x++;
	}
	return (tab_ms);
}

void	launch_julia(t_ms *ms)
{
	t_ms		tab_ms[8];
	pthread_t	thread[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void *)&tab_ms[i], (void *)ms, sizeof(t_ms));
		tab_ms[i].y = 0;
		tab_ms[i].y_max = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (i++ < 8)
		pthread_create(&thread[i - 1], NULL, julia_loop, &tab_ms[i - 1]);
	while (--i)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(ms->mlx, ms->win, ms->img, 0, 0);
	if (ms->text == 0)
		text(ms);
}

int		mouse_julia(int x, int y, t_ms *ms)
{
	if (ms->j_mouse == 1)
	{
		ms->c_r = x * 2;
		ms->c_i = y * 2 - 800;
		launch_fractal(ms);
	}
	return (0);
}

void	init_julia(t_ms *ms)
{
	ms->it_max = 30;
	ms->zoom = 200;
	ms->x1 = -2.0;
	ms->y1 = -1.8;
	ms->color = 15;
	ms->c_r = 0.285;
	ms->c_i = 0.01;
}
