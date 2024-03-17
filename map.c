/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:56:31 by mosh              #+#    #+#             */
/*   Updated: 2024/03/17 23:24:22 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


// void	init_zoom(t_coordinates *pos, int *x1, int *y1)
// {
// 	pos->x *= ZOOM;
// 	*x1 *= ZOOM;
// 	pos->y *= ZOOM;
// 	*y1 *= ZOOM;
// }

// void	init_point(t_coordinates *pos, int *x1, int *y1, t_point *point)
// {
// 	point->dx = ft_abs(*x1 - pos->x);
// 	point->dy = ft_abs(*y1 - pos->y);
// 	init_zoom(pos, x1, y1);
// 	if (pos->x < *x1)
// 		point->step_x = 1;
// 	else
// 		point->step_x = -1;
// 	if (pos->y < *y1)
// 		point->step_y = 1;
// 	else
// 		point->step_y = -1;
// 	point->err = point->dx - point->dy;
// }

// void	isometric_porjection(float *x, float *y, int *z, t_point point)
// {
// 	(void)point;
// 	// point.dx = *x * cos((float)) * *z;
// 	// point.dy = *y * sin((float)) * *z;
// 	float prev_x = *x;
// 	*x = prev_x - *y;
// 	*y = (prev_x + *y) * sin(M_PI / 6) - *z;
// }

// void	map_line(t_coordinates pos, int x1, int y1, t_fdf *data)
// {
// 	t_point	point;

// 	init_point(&pos, &x1, &y1, &point);
// 	init_zoom(&pos, &x1, &y1);
	// pos.z = data->matrix[pos.x][pos.y];
	// pos.z1 = data->matrix[x1][y1];
// 	isometric_porjection((float)pos.x, (float)pos.y, &pos.z, point);
// 	isometric_porjection(&x1, &y1, &pos.z1, point);
// 	while (1)
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos.x, pos.y, 0xFFFFFF);
// 		if (pos.x == x1 && pos.y == y1)
// 			break ;
// 		point.err2 = 2 * point.err;
// 		if (point.err2 > -point.dy)
// 		{
// 			point.err -= point.dy;
// 			pos.x += point.step_x;
// 		}
// 		if (point.err2 < point.dx)
// 		{
// 			point.err += point.dx;
// 			pos.y += point.step_y;
// 		}
// 	}
// }

// void	map_fdf(t_fdf *data)
// {
// 	t_coordinates	pos;

// 	pos.y = 0;
// 	while (data->height > pos.y)
// 	{
// 		pos.x = 0;
// 		while (data->width > pos.x)
// 		{
// 			if (data->width - 1 > pos.x)
// 				map_line(pos, pos.x + 1, pos.y, data);
// 			if (data->height - 1 > pos.y)
// 				map_line(pos, pos.x, pos.y + 1, data);
// 			pos.x++;
// 		}
// 		pos.y++;
// 	}
// }

void	init_zoom(t_coordinates *pos, int *x1, int *y1)
{
	pos->x *= ZOOM;
	*x1 *= ZOOM;
	pos->y *= ZOOM;
	*y1 *= ZOOM;
}

void	init_point(t_coordinates *pos, int *x1, int *y1, t_point *point)
{
	point->dx = ft_abs(*x1 - pos->x);
	point->dy = ft_abs(*y1 - pos->y);
	init_zoom(pos, x1, y1);
	if (pos->x < *x1)
		point->step_x = 1;
	else
		point->step_x = -1;
	if (pos->y < *y1)
		point->step_y = 1;
	else
		point->step_y = -1;
	point->err = point->dx - point->dy;
}

// void	isometric_porjection(float *x, float *y, int *z, t_point point)
// {
// 	(void)point;
// 	// point.dx = *x * cos((float)) * *z;
// 	// point.dy = *y * sin((float)) * *z;
// 	float prev_x = *x;
// 	*x = prev_x - *y;
// 	*y = (prev_x + *y) * sin(M_PI / 6) - *z;
// }

// void	map_line(t_coordinates pos, int x1, int y1, t_fdf *data)
// {
// 	t_point	point;

// 	init_point(&pos, &x1, &y1, &point);
// 	init_zoom(&pos, &x1, &y1);
// 	pos.z = data->matrix[pos.x][pos.y];
// 	pos.z1 = data->matrix[x1][y1];
// 	isometric_porjection((float)pos.x, (float)pos.y, &pos.z, point);
// 	isometric_porjection(&x1, &y1, &pos.z1, point);
// 	while (1)
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos.x, pos.y, 0xFFFFFF);
// 		if (pos.x == x1 && pos.y == y1)
// 			break ;
// 		point.err2 = 2 * point.err;
// 		if (point.err2 > -point.dy)
// 		{
// 			point.err -= point.dy;
// 			pos.x += point.step_x;
// 		}
// 		if (point.err2 < point.dx)
// 		{
// 			point.err += point.dx;
// 			pos.y += point.step_y;
// 		}
// 	}
// }

void	map_fdf(t_fdf *data)
{
	t_coordinates	pos;

	pos.y = 0;
	while (data->height > pos.y)
	{
		pos.x = 0;
		while (data->width > pos.x)
		{
			if (data->width - 1 > pos.x)
				line(pos.x, pos.y, pos.x + 1, pos.y, data);
			if (data->height - 1 > pos.y)
				line(pos.x, pos.y, pos.x, pos.y + 1, data);
			pos.x++;
		}
		pos.y++;
	}
}

# define MAX(a, b) (a > b ? a : b)


void	isometric_porjection(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;


}

float	mod(float i)
{
	if (i > 0)
	{
		return (i);
	}
	else if (i < 0)
		return (-1);
	return (0);
}

void	line(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	// int z = data->matrix[(int)x][(int)y];
	// int z1 = data->matrix[(int)x1][(int)y1];
	// data->color = (z || z1) ? 0xe80c0c : 0xFFFFFF;
	x *= ZOOM;
	x1 *= ZOOM;
	y *= ZOOM;
	y1 *= ZOOM;

	x_step = x1 - x;
	y_step = y1 - y;
	// isometric_porjection(&x, &y, z);
	// isometric_porjection(&x1, &y1, z1);

	max = MAX(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}