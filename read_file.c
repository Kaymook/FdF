/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:29 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/07 03:32:06 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int open_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (0 >= fd)
		exit(1);
	return (fd);
}

static int get_width(char *file)
{
	int width;
	int fd;
	char *line;

	fd = open_file(file);
	line = get_next_line(fd);
	if (!line)
		return (0);
	width = count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

static int get_height(char *file)
{
	int height;
	int fd;
	fd = open_file(file);
	height = 0;
	while (get_next_line(fd))
	{
		height++;
	}
	close(fd);
	return (height);
}

void read_fdf_file(char *file_name, t_fdf *data)
{
	int fd;
	char *gnl;
	t_loop count;

	data->width = get_width(file_name);
	data->height = get_height(file_name);
	fd = open_file(file_name);
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
	count.i = 0;
	while (count.i < data->height)
	{
		gnl = get_next_line(fd);
		make_matrix(data->matrix[count.i], gnl);
		count.i++;
	}
	data->matrix[count.i] =NULL;
	close(fd);
	return;
}

void make_matrix(int *data, char *gnl)
{
	char **split;
	t_loop count;

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

// while (1)
// {
// 	i = 0;
// 	gnl = get_next_line(fd);
// 	if (!gnl)
// 		break ;
// 	split = ft_split(gnl, ' ');
// 	if (!split)
// 		exit(1);
// 	while (split[i++] != NULL)
// 	{
// 		make_lst();
// 	}
// 	y++;
// 	free(gnl);
// 	free_split(split);
// }