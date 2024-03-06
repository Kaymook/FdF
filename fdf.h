/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:46:14 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/06 21:31:57 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sysexits.h>
# include "libft/libft.h"

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
#endif