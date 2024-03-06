/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:29 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/06 23:56:56 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_words(const char *s, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (0 > fd)
		exit(1);
	return (fd);
}

// static int	get_width(char *file)
// {
// 	int		width;
// 	int		fd;
// 	char	*line;

// 	fd = open_file(file);
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (0);
// 	width = count_words(line, ' ');
// 	free(line);
// 	close(fd);

// 	return (width);
// }

// static int	get_height(char *file)
// {
// 	int	height;
// 	int	fd;
// 	// char *str;

// 	fd = open_file(file);
// 	height = 0;
// 	// str = get_next_line(fd);
// 	height++;
// 	while (get_next_line(fd))
// 	{
// 		// str = get_next_line(fd);
// 		// free(str);
// 		height++;
// 		printf("%d\n", height);
// 	}
// 	close(fd);
// 	return (height);
// }

static int	get_height(char *file, t_fdf *data)
{
	int		height;
	int		fd;
	char	*str;

	fd = open_file(file);
	height = 0;
	str = get_next_line(fd);
	data->width = count_words(str, ' ');
	// height++;
	while (str != NULL)
	{
		str = get_next_line(fd);
		height++;
	}
	close(fd);
	return (height);
}

void	read_fdf_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*gnl;
	t_loop	count;

	fd = open_file(file_name);
	// data->width = get_width(file_name);
	data->height = get_height(file_name, data);
	data->matrix = malloc(sizeof(int *) * (data->height + 1));
	if (!data->matrix)
		exit(1);
	count.i = 0;
	while (data->height > count.i)
	{
		data->matrix[count.i] = malloc(sizeof(int) * (data->width + 1));
		if (!data->matrix[count.i])
			exit(1);
		count.i++;
	}
	count.i = 0;
	while (data->height > count.i)
	{
		gnl = get_next_line(fd);
		make_matrix(data->matrix[count.i], gnl);
		count.i++;
	}
	// puts("aaaa");
	close(fd);
	return ;
}

void	make_matrix(int *data, char *gnl)
{
	char	**split;
	t_loop	count;

	count.i = 0;
	split = ft_split(gnl, ' ');
	while (split[count.i] != NULL)
	{
		data[count.i] = ft_atoi(split[count.i]);
		// printf("%d\n", count.i);
		// free(split[count.i]);
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