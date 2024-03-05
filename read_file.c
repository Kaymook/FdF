/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:29 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/05 16:35:41 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (0 > fd)
		file_error();
	return (fd);
}

int	get_width(char *file)
{
	int 	width;
	int 	fd;
	char	*line;

	fd = open_file(file);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	width = count_words(line);
	return (width);
}

int	get_height(char *file)
{
	int 	height;
	int 	fd;
	char	*line;

	fd = open_file(file);
	while (get_next_line(fd))
	{
		height++;
	}
	return (height);
}

void	read_file(char *file_name, t_fdf data)
{
	data.width = get_width(file_name);
	data.height = get_height(file_name);
	while (1)
	{
		i = 0;
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
		split = ft_split(gnl, ' ');
		if (!split)
			exit(1);
		while (split[i++] != NULL)
		{
			make_lst();
		}
		y++;
		free(gnl);
		free_split(split);
	}
	close(fd);
	return (0);
}

}
	