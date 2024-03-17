/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:46:14 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/17 22:50:41 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sysexits.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdio.h>
# include <math.h>

# define ZOOM 15
# define WIN_WIDTH 2000
# define WIN_HEIGHT 2000

typedef struct s_point
{
	float	dx;
	float	dy;
	float	step_x;
	float	step_y;
	float	err;
	float	err2;
}	t_point;

typedef struct s_loop
{
	int	i;
	int	j;
}	t_loop;

typedef struct s_coordinates {
	int	x;
	int	y;
	int	z;
	int	z1;
}	t_coordinates;

typedef struct s_fdf
{
	float		x;
	float		y;
	float		z;
	int			height;
	int			width;
	int			fd;
	int			**matrix;
	void		*mlx_ptr;
	void		*win_ptr;
	t_point		point;
	uint32_t	color;
}	t_fdf;


void	arg_error(int error);
void	read_fdf_file(char *file_name, t_fdf *data);
void	make_matrix(int *data, char *gnl);
// void	map_line(t_coordinates pos, int x1, int y1, t_fdf *data);
void	map_fdf(t_fdf *data);
void	line(float x, float y, float x1, float y1, t_fdf *data);
#endif
