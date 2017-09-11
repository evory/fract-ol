/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:07:06 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/11 20:38:18 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_mandelbrot(t_ms *ms)
{
	ms->it_max = 150;
	ms->zoom = 300;
	ms->x1 = -2.0;
	ms->y1 = -1.4;
	ms->color = 265;
}

void	mandelbrot(t_ms *ms)
{
	ms->c_r = ms->x / ms->zoom + ms->x1;
	ms->c_i = ms->y / ms->zoom + ms->y1;
	ms->z_r = 0;
	ms->z_i = 0;
	ms->it = 0;
	while (ms->z_r * ms->z_r + ms->z_i *
			ms->z_i < 4 && ms->it < ms->it_max)
	{
		ms->tmp = ms->z_r;
		ms->z_r = ms->z_r * ms->z_r -
			ms->z_i * ms->z_i + ms->c_r;
		ms->z_i = 2 * ms->z_i * ms->tmp + ms->c_i;
		ms->it++;
	}
	if (ms->it == ms->it_max)
		put_pxl_to_img(ms, ms->x, ms->y, 0x000000);
	else
		put_pxl_to_img(ms, ms->x, ms->y, (ms->color * ms->it));
}

void	*mandelbrot_loop(void *tab)
{
	t_ms	*ms;
	double	tmp;

	ms = (t_ms *)tab;
	ms->x = 0;
	tmp = ms->y;
	while (ms->x < WIDTH)
	{
		ms->y = tmp;
		while (ms->y < ms->y_max)
		{
			mandelbrot(ms);
			ms->y++;
		}
		ms->x++;
	}
	return (tab);
}

void	launch_mandelbrot(t_ms *ms)
{
	t_ms		tab[8];
	pthread_t	t[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&tab[i], (void*)ms, sizeof(t_ms));
		tab[i].y = 100 * i;
		tab[i].y_max = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&t[i - 1], NULL, mandelbrot_loop, &tab[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(ms->mlx, ms->win, ms->img, 0, 0);
	if (ms->text == 0)
		text(ms);
}
