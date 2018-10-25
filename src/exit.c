/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 11:23:36 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 21:00:52 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_error(int error)
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
	else if (error == ERROR_NO_DATA)
		ft_printf("{red}ERROR_NO_DATA{eoc}\n");
	exit(0);
}

static void		ft_free(t_fdf *fdf)
{
	if (fdf->map)
		free(fdf->map);
	if (fdf->coordx)
		free(fdf->coordx);
	if (fdf->coordy)
		free(fdf->coordy);
	if (fdf->color)
		free(fdf->color);
}

void			ft_exit(t_fdf *fdf, int error)
{
	int		i;

	i = -1;
	if (fdf->map)
		while (fdf->map[++i] && i < fdf->nb_line)
			free(fdf->map[i]);
	i = -1;
	if (fdf->coordx)
		while (fdf->coordx[++i] && i < fdf->nb_line)
			free(fdf->coordx[i]);
	i = -1;
	if (fdf->coordy)
		while (fdf->coordy[++i] && i < fdf->nb_line)
			free(fdf->coordy[i]);
	ft_free(fdf);
	if (fdf)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		free(fdf);
	}
	ft_error(error);
}
