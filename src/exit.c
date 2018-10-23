/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 11:23:36 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/21 15:28:15 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_error(int error)
{
	if (error == ERROR_MALLOC)
		ft_printf("{red}ERROR_MALLOC_FAILED{eoc}\n");
	else if (error == ERROR_BAD_CHAR)
		ft_printf("{red}ERROR_BAD_CHAR{eoc}\n");
	else if (error == ERROR_LIMIT_INT)
		ft_printf("{red}ERRROR_LIMIT_INT{eoc}\n");
	else if (error == ERROR_BAD_IDENDATION)
		ft_printf("{red}ERROR_BAD_IDENDATION{eoc}\n");
	else if (error == ERROR_NO_FILE)
		ft_printf("{red}Usage no file : ./fdf {file}{eoc}\n");
	else if (error == ERROR_TOO_MANY_FILES)
		ft_printf("{red}Usage too many files : ./fdf {file}{eoc}\n");
	else if (error == ERROR_OPEN)
		ft_printf("{red}ERROR_OPEN_FAILED{eoc}\n");
}

void			ft_exit(t_fdf *fdf, int error)
{
	int		i;

	i = 0;
	if (error < 0)
		ft_error(error);
	while (i < fdf->nb_line)
	{
		free(fdf->map[i]);
		i++;
	}
	if (fdf->map)
		free(fdf->map);
	if (fdf->img)
		free(fdf->img);
	if (fdf)
		free(fdf);
	exit(0);
}
