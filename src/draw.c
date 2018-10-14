/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:23:19 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/14 14:07:42 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_draw_one_line(t_fdf *fdf)
{
	int		x1;

	x1 = fdf->x + fdf->xlen;
	while (fdf->x < x1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y, 0xFFFFFF);
		fdf->x++;
		// if (fdf->x % 3 == 0)
		// 	fdf->y++;
	}
	return (SUCCESS);
}

static int		ft_draw_one_line2(t_fdf *fdf)
{
	int		y1;


	y1 = fdf->y + fdf->ylen;
	while (fdf->y < y1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x, fdf->y, 0xFFFFFF);
		fdf->y++;
	}
	return (SUCCESS);
}

extern int 		ft_draw(t_fdf *fdf)
{
	int		i;

	i = 0;
	fdf->xlen = (WIDTH - EDGE * 2) / fdf->nb_column;
	fdf->ylen = (HEIGHT - EDGE * 2) / fdf->nb_line;
	printf("fdf->ylen = %d fdf->y %d\n", fdf->ylen, fdf->y);
	printf("fdf->y = %d < (fdf->ylen * fdf->nb_line) = %d\n",fdf->y, fdf->ylen * fdf->nb_line);
	// fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, fdf->name);
	// while (i < fdf->nb_column)
	// {
	// 	while (fdf->x < (fdf->xlen * fdf->nb_column))
	// 		ft_draw_one_line(fdf);
	// 	i++;
	// 	fdf->x = EDGE;
	// 	fdf->y = EDGE + (fdf->ylen * i);
	// }
	// i = 0;
	// fdf->x = EDGE;
	// fdf->y = EDGE;
	// while (i < fdf->nb_line)
	// {
		while (fdf->y < (fdf->ylen * fdf->nb_line))
			ft_draw_one_line2(fdf);
	// 	i++;
	// 	fdf->x = EDGE + (fdf->xlen * i);
	// 	fdf->y = EDGE;
	// }
	// mlx_loop(fdf->mlx);
	return (SUCCESS);
}
