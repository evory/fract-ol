/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 16:12:58 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/11 16:25:18 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fractol.h"

void	ft_pixel_put(t_ms *ms, int x, int y)
{
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
			ms->data[(y * ms->s_l) + (x * (ms->bpp / 8)) + 0] = 255;
			ms->data[(y * ms->s_l) + (x * (ms->bpp / 8)) + 1] = 25;
			ms->data[(y * ms->s_l) + (x * (ms->bpp / 8)) + 2] = 255;
	}
}

// int		mandelbrot(t_ms *ms, int x, int y)
// {
// 	int iteration_max = 50;
// // Pour chaque point de coordonnées (x; y) du plan :
// 	int i = 0;
//     int z = 0;
// 	int c = x + i * y;
//
// 	z = z * z + c;
//     i = i + 1;
//     while (z < 2 && i < iteration_max)
// 	{
// 		// if (i == iteration_max)
// 		ft_pixel_put(ms, x, y); // dessiner le pixel correspondant au point de coordonné (x; y)
// 		i++;
// 	}
// 	return (0);
// }
//
int	loop(t_ms *ms)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_pixel_put(ms, x, y);
			// mandelbrot(ms, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
