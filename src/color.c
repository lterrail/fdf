/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:06:46 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/23 19:40:10 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		degradeblue(t_fdf *fdf, t_color *color, int x, int y)
{
	float r;
	float g;

	if ((r = fabs(fdf->map[y][x] * (fdf->alti * 10))) > 245)
	{
		r = 245;
		g = 170;
	}
	else
		g = fabs(fdf->map[y][x] * (fdf->alti * 4));
	color->r = 255 - r;
	color->g = 255 - g;
	color->b = 255;
}

static void		degradeorange(t_fdf *fdf, t_color *color, int x, int y)
{
	float g;
	float b;

	if ((g = fabs(fdf->map[y][x] * (fdf->alti * 20))) > 245)
	{
		g = 245;
		b = 170;
	}
	else
		b = fabs(fdf->map[y][x] * (fdf->alti * 16));
	color->r = 255;
	color->g = 255 - g;
	color->b = 255 - b;
}

static void	ft_color_earth(t_fdf *fdf, t_color *color, int x, int y)
{
	int		alti;

	alti = fdf->alti + 1;
	if (fdf->map[y][x] * alti <= 0)
		blue1(color);
	else if (fdf->map[y][x] * alti >= 1 && fdf->map[y][x] * alti <= 4)
		yellow1(color);
	else if (fdf->map[y][x] * alti >= 5 && fdf->map[y][x] * alti <= 9)
		green1(color);
	else if (fdf->map[y][x] * alti >= 10 && fdf->map[y][x] * alti <= 13)
		green2(color);
	else if (fdf->map[y][x] * alti >= 14 && fdf->map[y][x] * alti <= 30)
		brawn1(color);
	else if (fdf->map[y][x] * alti >= 31 && fdf->map[y][x] * alti <= 65)
		brawn2(color);
	else if (fdf->map[y][x] * alti >= 66)
		white(color);
}

static void	random_color(t_color *color, int r, int g, int b)
{
	int		i;

	i = 0;
	color->r = (color->r + r) % 255;
	color->g = (color->g + g) % 255;
	color->b = (color->b + b) % 255;
}

void		ft_color(t_fdf *fdf, t_color *color, int x, int y)
{
	if (fdf->key == 1)
		ft_color_earth(fdf, color, x, y);
	else if (fdf->key == 2)
		degradeblue(fdf, color, x, y);
	else if (fdf->key == 3)
		degradeorange(fdf, color, x, y);
	else if (fdf->key == 4)
		green1(color);
	else if (fdf->key == 5)
		blue1(color);
	else if (fdf->key == 6)
		red1(color);
	else if (fdf->key == 7)
		yellow1(color);
	else if (fdf->key == 8)
		random_color(color, 89, 69, 49);
	else if (fdf->key == 9)
		random_color(color, 29, 79, 149);
	else
		white(color);
}
