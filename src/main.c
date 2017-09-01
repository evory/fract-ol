/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:12:50 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/01 15:35:06 by bbrandt          ###   ########.fr       */
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

int		main(int argc, char const **argv)
{
	t_ms	*ms;

	if (!(ms = (t_ms *)malloc(sizeof(t_ms))))
		return (-1);
	if (argc != 2)
	{
		ft_putendl("usage : ./fractol [julia, mandelbrot or choose]");
		return (0);
	}
	ft_init_mlx(ms);
	check_name(ms, argv[1]);
	launch_fractal(ms);

	mlx_hook(ms->win, 2, 1, key_hook, ms);
	mlx_loop(ms->mlx);
	free(&ms);
	return (0);
}
