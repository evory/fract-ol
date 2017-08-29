/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 15:36:48 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/29 17:38:29 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_julia(t_ms *ms)
{
	ms->it_max = 40;
	ms->zoom = 200;
	ms->x1 = -2.0;
	ms->y1 = -1.9;
	ms->color = 265;
	ms->c_r = 0.285;
	ms->c_i = 0.01;
	ms->mouse = 1;
}
