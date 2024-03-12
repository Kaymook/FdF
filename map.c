/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:56:31 by mosh              #+#    #+#             */
/*   Updated: 2024/03/12 14:25:54 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void line(int x0, int y0, int x1, int y1, t_fdf *data)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx;
	int sy;

    if (x0 < x1)
		sx = 1;
	else
		sx = -1;
    if (y0 < y1)
		sy = 1;
	else
		sy = -1;
    int err = dx - dy;

	while (1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0xFFFFFF);

		if (x0 == x1 && y0 == y1)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
