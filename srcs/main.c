/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:12:50 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/11 20:26:32 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		main(int argc, char const **argv)
{
	t_ms	*ms;

	if (!(ms = (t_ms *)malloc(sizeof(t_ms))))
		return (-1);
	if (argc != 1)
	{
		ft_putendl("no parameters require, launch ./fractol alone");
		return (0);
	}
	ms->name = 1;
	ft_init_mlx(ms);
	choose_launcher(ms);
	mlx_hook(ms->win, 6, 1L << 6, mouse_julia, ms);
	mlx_hook(ms->win, 2, 1, key_hook, ms);
	mlx_mouse_hook(ms->win, mouse_zoom, ms);
	mlx_loop(ms->mlx);
	free(&ms);
	return (0);
}
