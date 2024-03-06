/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:23:35 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/06 19:47:03 by kmoshker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	arg_error(int error)
{
	if (error == 2)
	{
		return ;
	}
	else
	{
		if (error < 2)
		{
			printf("Please execute your fdf program using the file\n");
		}
		else if (error > 2)
		{
			printf("Too many arguments, retry \n");
		}
		exit(EX_USAGE);
	}
}

void	file_error(void)
{
	printf("could not open the file, retry");
}
