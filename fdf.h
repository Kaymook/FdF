/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:46:14 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/12 18:09:35 by mosh             ###   ########.fr       */
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

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_loop
{
	int	i;
	int	j;
}	t_loop;

typedef struct s_fdf
{
	int			height;
	int			width;
	int			**matrix;
	void		*mlx_ptr;
	void		*win_ptr;
	t_point		point;
	uint32_t	color;
}	t_fdf;


void	arg_error(int error);
void	read_fdf_file(char *file_name, t_fdf *data);
void	make_matrix(int *data, char *gnl);
void	line(int x0, int y0, int x1, int y1, t_fdf *data);
void	map_fdf(t_fdf data);

#endif
