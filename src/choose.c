/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:07:25 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/29 17:38:32 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	init_choose(t_ms *ms)
{
	ms->it_max = 40;
	ms->zoom = 300;
	ms->x1 = -2.05;
	ms->y1 = -1.3;
	ms->color = 265;
}