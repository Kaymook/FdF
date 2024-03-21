/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:47:09 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/21 09:42:32 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_loop	count;

	count.i = 0;
	fdf = (t_fdf *)malloc (sizeof(t_fdf));
	arg_error(argc);
	read_fdf_file(argv[1], fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "FDF");
	map_fdf(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
