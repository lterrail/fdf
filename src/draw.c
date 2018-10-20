/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:23:19 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/20 18:54:18 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_draw_one_dash_x(t_fdf *fdf)
{
	while (fdf->x < fdf->xnext)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y, 0xFFFFFF);
		fdf->x++;
	}
	return (SUCCESS);
}

static int		ft_draw_one_dash_y(t_fdf *fdf)
{
	while (fdf->y < fdf->ynext)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y, 0xFFFFFF);
		fdf->y++;
	}
	return (SUCCESS);
}

static int		ft_draw_one_line_x(t_fdf *fdf)
{
	int		i;

	i = 1;
	while (i < fdf->nb_column)
	{
		ft_draw_one_dash_x(fdf);
		fdf->xnext += fdf->xlen;
		i++;
	}
	return (SUCCESS);
}

static int		ft_draw_one_line_y(t_fdf *fdf)
{
	int		i;

	i = 1;
	while (i < fdf->nb_line)
	{
		ft_draw_one_dash_y(fdf);
		fdf->ynext += fdf->ylen;
		i++;
	}
	return (SUCCESS);
}

extern int 		ft_draw(t_fdf *fdf)
{
	int		i;

	fdf->xlen = (WIDTH - EDGE * 3) / (fdf->nb_column - 1);
	fdf->ylen = (HEIGHT - EDGE * 3) / (fdf->nb_line - 1);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, fdf->name);
	i = 0;
	while (i < fdf->nb_line)
	{
		fdf->y = EDGE + fdf->ylen * i;
		fdf->x = EDGE;
		fdf->xnext = fdf->x + fdf->xlen;
		ft_draw_one_line_x(fdf);
		i++;
	}
	i = 0;
	while (i < fdf->nb_column)
	{
		fdf->x = EDGE + fdf->xlen * i;
		fdf->y = EDGE;
		fdf->ynext = fdf->y + fdf->ylen;
		ft_draw_one_line_y(fdf);
		i++;
	}
	mlx_loop(fdf->mlx);
	return (SUCCESS);
}
