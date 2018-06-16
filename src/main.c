/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:54:41 by lterrail          #+#    #+#             */
/*   Updated: 2018/06/16 14:49:50 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(t_fdf *parse)
{
	if (parser(parse) == -1)
	{
		ft_putendl("Error");
		return ;
	}
	mlx(parse);
}

int		main(int ac, char **av)
{
	t_fdf	mine;

	if (ac == 2)
	{
		mine.name = av[1];
		mine.fd = open(mine.name, O_RDONLY);
		fdf(&mine);
	}
	else
		ft_putendl("usage: ./fdf file");
	return (0);
}
