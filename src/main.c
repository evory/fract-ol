/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:12:50 by bbrandt           #+#    #+#             */
/*   Updated: 2017/07/26 17:38:24 by bbrandt          ###   ########.fr       */
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

void	ft_reset_px(t_ms *ms)
{

}

int		ft_init_mlx(t_ms *ms)
{
	ft_reset_px(ms);
	ms->img = mlx_new_image(ms->mlx, WIDTH, HEIGHT);
	ms->data = mlx_get_data_addr(ms->img, &ms->bpp, &ms->s_l, &ms->endian);
	mlx_put_image_to_window(ms->mlx, ms->win, ms->img, 0, 0);
	return (0);
}

int main(int argc, char const *argv[])
{
	t_ms	ms;

	if (argc != 2)
	{
		ft_putstr("please insert \"julia\" \"mendel\" or \"CHOOSE\"\n");
		return (0);
	}
	ms.mlx = mlx_init();
	ms.win = mlx_new_window(ms.mlx, WIDTH, HEIGHT, "fractol");
	ft_init_mlx(&ms);
	mlx_hook(ms.win, KEYPRESS, KEYPRESSMASK, key_hook, &ms);
	mlx_loop(ms.mlx);
	free(&ms);
	return (0);
}
