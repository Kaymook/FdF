/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:46:14 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/05 16:10:30 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sysexits.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_fdf
{
	double		x;
	double		y;
	double		z;
	int			height;
	int			width;
	char		**matrix;
	void		*mlx_ptr;
	void		*win_ptr;
	uint32_t	color;
}	t_fdf;

typedef struct s_point
{
	
}

void	arg_error(int error);

#endif