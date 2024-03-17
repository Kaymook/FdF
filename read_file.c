/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:29 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/17 23:07:08 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (0 >= fd)
		exit(1);
	return (fd);
}

static int	get_width(char *file)
{
	int		width;
	int		fd;
	char	*line;

	fd = open_file(file);
	line = get_next_line(fd);
	if (!line)
		return (1);
	width = count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

static int	get_height(char *file)
{
	int	height;
	int	fd;

	fd = open_file(file);
	height = 0;
	while (get_next_line(fd))
	{
		height++;
	}
	close(fd);
	return (height);
}


void	make_matrix(int *data, char *gnl)
{
	char	**split;
	t_loop	count;

	count.i = 0;
	split = ft_split(gnl, ' ');
	if (!split)
		exit(1);
	while (split[count.i] != NULL)
	{
		data[count.i] = ft_atoi(split[count.i]);
		free(split[count.i]);
		count.i++;
	}
	free(split);
}

void	init_matrix(char *file_name, t_fdf *data)
{
	t_loop	count;

	data->width = get_width(file_name);
	data->height = get_height(file_name);
	data->fd = open_file(file_name);
	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->matrix)
		exit(1);
	count.i = 0;
	while (count.i < data->height)
	{
		data->matrix[count.i] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (!data->matrix[count.i])
			exit(1);
		count.i++;
	}	
}

void	read_fdf_file(char *file_name, t_fdf *data)
{
	char	*gnl;
	t_loop	count;

	init_matrix(file_name, data);
	count.i = 0;
	while (count.i < data->height)
	{
		gnl = get_next_line(data->fd);
		make_matrix(data->matrix[count.i], gnl);
		count.i++;
	}
	data->matrix[count.i] = NULL;
	close(data->fd);
}

