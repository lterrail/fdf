/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:23:19 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/23 17:45:57 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_draw_line(t_fdf *fdf, int x, int y, t_color *color)
{
	t_next	next;

	next.xdest = fdf->coordx[y][x];
	next.ydest = fdf->coordy[y][x];
	if (x != 0 && y == 0)
	{
		next.xsrc = fdf->coordx[y][x - 1];
		next.ysrc = fdf->coordy[y][x - 1];
		draw_line(fdf->img, &next, color);
	}
	if (x == 0 && y != 0)
	{
		next.xsrc = fdf->coordx[y - 1][x];
		next.ysrc = fdf->coordy[y - 1][x];
		draw_line(fdf->img, &next, color);
	}
	else if (x != 0 && y != 0)
	{
		next.xsrc = fdf->coordx[y][x - 1];
		next.ysrc = fdf->coordy[y][x - 1];
		draw_line(fdf->img, &next, color);
		next.xsrc = fdf->coordx[y - 1][x];
		next.ysrc = fdf->coordy[y - 1][x];
		draw_line(fdf->img, &next, color);
	}
}

static void		define_coord_xy(t_fdf *fdf, int x, int y)
{
	float		coord_x;
	float		coord_y;
	float		angle_x;
	float		angle_y;
	t_color		color;

	ft_color(fdf, &color, x, y);
	angle_x = angle(fdf, x, y, 1);
	angle_y = angle(fdf, x, y, 0);
	coord_x = coord(fdf, angle_x, angle_y, 1);
	coord_y = coord(fdf, angle_x, angle_y, 0);
	coord_y -= ((fdf->size / 2 * fdf->map[y][x]) * fdf->alti);
	fdf->coordx[y][x] = coord_x + fdf->move_x;
	fdf->coordy[y][x] = coord_y + fdf->move_y;
	init_draw_line(fdf, x, y, &color);
}

extern int 		ft_draw(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->nb_line)
	{
		x = 0;
		while (x < fdf->nb_column)
		{
			define_coord_xy(fdf, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	return (SUCCESS);
}
