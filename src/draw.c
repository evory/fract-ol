/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 16:12:58 by bbrandt           #+#    #+#             */
/*   Updated: 2017/08/22 23:08:26 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fractol.h"

void	ft_pixel_put(t_ms *ms, int x, int y)
{
	if (x > 0 && y > 0 && x < WIDTH && y < HEIGHT)
	{
			ms->pixels[(y * ms->s_l) + (x * (ms->bpp / 8)) + 0] = ms->b;
			ms->pixels[(y * ms->s_l) + (x * (ms->bpp / 8)) + 1] = ms->g;
			ms->pixels[(y * ms->s_l) + (x * (ms->bpp / 8)) + 2] = ms->r;
	}
}


void draw()
{
  // loat angle = 0;
  //
  // // float ca = map(mouseX, 0, width, -1, 1);//-0.70176;
  // // float cb = map(mouseY, 0, height, -1, 1);//-0.3842;
  //
  // loat ca = cos(angle * 3.213);//sin(angle);
  // loat cb = sin(angle);
  //
  // ngle += 0.02;
  //
  // // Establish a range of values on the complex plane
  // // A different range will allow us to "zoom" in or out on the fractal
  //
  // // It all starts with the width, try higher or lower values
  // //float w = abs(sin(angle))*5;
  // float w = 5;
  // float h = (w * height) / width;
  //
  // // Start at negative half the width and height
  // float xmin = -w/2;
  // float ymin = -h/2;
  //
  // // Make sure we can write to the pixels[] array.
  // // Only need to do this once since we don't do any other drawing.
  // loadPixels();
  //
  // // Maximum number of iterations for each point on the complex plane
  // int maxiterations = 100;
  //
  // // x goes from xmin to xmax
  // float xmax = xmin + w;
  // // y goes from ymin to ymax
  // float ymax = ymin + h;
  //
  // // Calculate amount we increment x,y for each pixel
  // float dx = (xmax - xmin) / (width);
  // float dy = (ymax - ymin) / (height);
  //
  // // Start y
  // loat y = ymin;
  // nt j;
  //  = 0;
  // while (j < height)
  //
  //    // Start x
  //    float x = xmin;
  // int i;
  // i = 0;
  //
  //    while (i < width)
  // {
  // 		// Now we test, as we iterate z = z^2 + cm does z tend towards infinity?
  //     float a = x;
  //     float b = y;
  //     int n = 0;
  //     while (n < maxiterations)
  // 	{
  //     	float aa = a * a;
  //         float bb = b * b;
  //         // Infinity in our finite world is simple, let's just consider it 16
  //         if (aa + bb > 4.0)
  //         	break;
  //         float twoab = 2.0 * a * b;
  //         a = aa - bb + ca;
  //         b = twoab + cb;
  //         n++;
  // 	}
  //
  //     // We color each pixel based on how long it takes to get to infinity
  //     // If we never got there, let's pick the color black
  //     if (n == maxiterations)
  // 		pixels[i+j*width] = color(0);
  // 	else
  // 	{
  //   			// Gosh, we could make fancy colors here if we wanted
  // 		float hu = sqrt(float(n) / maxiterations);
  //     	pixels[i+j*width] = color(hu, 255, 150);
  //     }
  // 		x += dx;
  // 		i++;
  // }
  //   	y += dy;
  // j++;
  //
  // updatePixels();
  // println(frameRate);
}
