/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:12:50 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/22 23:08:25 by bbrandt          ###   ########.fr       */
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

int		ft_init_mlx(t_ms *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WIDTH, HEIGHT, "fractol");
	ms->img = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	ms->pixels = mlx_get_data_addr(ms->img, &ms->bpp, &ms->s_l, &ms->endian);
	draw();
	mlx_put_image_to_window(ms->mlx, ms->win, ms->img, 0, 0);
	return (0);
}

t_ms	*init_env(void)
{
	t_ms *ms;

	ms = malloc(sizeof(ms));
	ms->r = 10;
	ms->g = 20;
	ms->b = 30;
	return (ms);
}

int		check_name(char const *name)
{
	if (ft_strcmp(name, "julia") == 0 || ft_strcmp(name, "mandelbrot") == 0
	|| ft_strcmp(name, "choose") == 0)
		return (1);
	else
	{
		ft_putstr("usage : ./fractol [julia, mandelbrot or CHOOSE]\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		main(int argc, char const **argv)
{
	t_ms	*ms;

	if (argc != 2)
	{
		ft_putstr("usage : ./fractol [julia, mandelbrot or CHOOSE]\n");
		return (0);
	}
	check_name(argv[1]);
	ms = init_env();
	ft_init_mlx(ms);
	mlx_hook(ms->win, KEYPRESS, KEYPRESSMASK, key_hook, &ms);
	mlx_loop(ms->mlx);
	free(&ms);
	return (0);
}
