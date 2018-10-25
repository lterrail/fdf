/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:06:46 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 21:16:52 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	degradeblue(t_fdf *fdf, t_color *color, int x, int y)
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
	if (fdf->map[y][x] <= 0)
	{
		color->r = 0;
		color->b = 0;
		color->g = 0;
	}
}

static void	degradeorange(t_fdf *fdf, t_color *color, int x, int y)
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

	alti = fabs(fdf->alti) + 1;
	if (fdf->map[y][x] * alti == 0)
		blue1(color);
	else if (fdf->map[y][x] * alti < 0)
		blue2(color);
	else if (fdf->map[y][x] * alti >= 1 && fdf->map[y][x] * alti <= 4)
		yellow1(color);
	else if (fdf->map[y][x] * alti >= 5 && fdf->map[y][x] * alti <= 9)
		green1(color);
	else if (fdf->map[y][x] * alti >= 10 && fdf->map[y][x] * alti <= 13)
		green2(color);
	else if (fdf->map[y][x] * alti >= 14 && fdf->map[y][x] * alti <= 30)
		brawn1(color);
	else if (fdf->map[y][x] * alti >= 31 && fdf->map[y][x] * alti <= 50)
		brawn2(color);
	else if (fdf->map[y][x] * alti >= 51 && fdf->map[y][x] * alti <= 65)
		grey1(color);
	else if (fdf->map[y][x] * alti >= 66)
		white(color);
}

static void	random_color(t_color *color, int flag)
{
	int		i;

	i = 0;
	if (flag == 0)
	{
		color->r += 89 % 255;
		color->g += 69 % 255;
		color->b += 49 % 255;
	}
	else
	{
		color->r = color->random_color % 255;
		color->g = color->random_color * 2 % 255;
		color->b = color->random_color * 4 % 255;
	}
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
		random_color(color, 0);
	else if (fdf->key == 9)
		random_color(color, 1);
	else
		white(color);
}
