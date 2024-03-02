/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:47:09 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/02 18:54:02 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*gnl;
	char	**split;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (0 >= fd)
		error("");		//errorメッセージとexit処理を実装
	while (1)
	{
		i = 0;
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		split = ft_split(gnl, ' ');
		while (split[i] != NULL)
		{
			make_lst();
		}
	}
	close(fd);
	return (0);
}