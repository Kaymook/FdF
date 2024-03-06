/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:47:09 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/06 23:36:31 by kmoshker         ###   ########.fr       */
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
	while (fdf->height >= count.i++)
	{
		count.j = 0;
		while (fdf->width >= count.j)
			printf("%3d", fdf->matrix[count.i][count.j++]);
		printf("\n");
	}
	return (0);
}
