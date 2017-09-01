/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 15:17:06 by bbrandt           #+#    #+#             */
/*   Updated: 2017/09/01 15:54:07 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
		ms->zoom += 10;
	if (keycode == 78)
		ms->zoom -= 10;
	if (keycode == 83)
		ms->color = 1047111;
	choose_launcher(ms);
	return (0);
}
