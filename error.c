/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoshker <kmoshker@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:23:35 by kmoshker          #+#    #+#             */
/*   Updated: 2024/03/05 16:28:09 by kmoshker         ###   ########.fr       */
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
			ft_printf("Please execute your fdf program using the file\n");
		}
		else if (error > 2)
		{
			ft_printf("Too many arguments, retry \n");
		}
		exit(EX_USAGE);
	}
}

void	file_error(void)
{
	ft_printf("could not open the file, retry");
}
