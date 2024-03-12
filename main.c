/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:47:09 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/12 15:45:41 by mosh             ###   ########.fr       */
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
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1500, "FDF");
	line(100, 100, 400, 400, fdf);
	mlx_loop(fdf->mlx_ptr);
	// while (fdf->height > count.i)
	// {
	// 	count.j = 0;
	// 	while (fdf->width > count.j)
	// 		printf("%3d", fdf->matrix[count.i][count.j++]);
	// 	count.i++;
	// 	printf("\n");
		
	// }
	return (0);
}
