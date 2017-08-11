/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:12:50 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/11 16:49:06 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		key_hook(int keycode, t_ms *ms)
{
	if (keycode == EXIT)
		exit(EXIT_SUCCESS);

	mlx_destroy_image(ms->mlx, ms->img);
	return (0);
}

t_ms init_env(t_ms *ms, char const *name)
{
	ms = (t_ms*)malloc(sizeof(ms));
	ms->name = name;
	return (*ms);
}

int		ft_init_mlx(t_ms *ms)
{
	ms->mlx = mlx_init();
	ms->win = mlx_new_window(ms->mlx, WIDTH, HEIGHT, "fractol");
	ms->img = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	ms->data = mlx_get_data_addr(ms->img, &ms->bpp, &ms->s_l, &ms->endian);
	loop(ms);
	mlx_put_image_to_window(ms->mlx, ms->win, ms->img, 0, 0);
	return (0);
}

int		check_name(char const *name)
{
	if (ft_strcmp(name, "julia") == 0 || ft_strcmp(name, "mandelbrot") == 0
	|| ft_strcmp(name, "chose") == 0)
		return (1);
	else
		ft_putstr("please insert \"julia,\" \"mandelbrot\" or \"CHOOSE\"\n");
	return (0);
}

int 	main(int argc, char const *argv[])
{
	t_ms	ms;

	if (argc != 2)
	{
		ft_putstr("please insert \"julia,\" \"mandelbrot\" or \"CHOOSE\"\n");
		return (0);
	}
	if (check_name(argv[1]) == 0)
		exit(EXIT_SUCCESS);

	ms = init_env(&ms, argv[1]);

	ft_init_mlx(&ms);

printf("%s\n", ms.name);

	mlx_hook(ms.win, KEYPRESS, KEYPRESSMASK, key_hook, &ms);
	mlx_loop(ms.mlx);
	free(&ms);
	return (0);
}
