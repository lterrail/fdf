/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:07:59 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/23 18:39:54 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(t_img *img, int x, int y, t_color *color)
{
	img->data[(x * (img->bpp / 8)) + (y * img->size_line)] = color->b;
	img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 1] = color->g;
	img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 2] = color->r;
}


static void		dy_dx(t_img *img, t_color *color, t_line *line)
{
	line->cumul = 0;
	while (line->i < line->dy)
	{
		line->y += line->yincr;
		line->cumul += line->dx;
		if (line->cumul >= line->dy)
		{
			line->cumul -= line->dy;
			line->x += line->xincr;
		}
		if ((line->x >= 0 && line->x <= WIDTH - 1) &&
			(line->y >= 1 && line->y <= HEIGHT - 1))
			draw_pixel(img, line->x, line->y, color);
		line->i++;
	}
}

static void		dx_dy(t_img *img, t_color *color, t_line *line)
{
	line->cumul = 0;
	while (line->i < line->dx)
	{
		line->x += line->xincr;
		line->cumul += line->dy;
		if (line->cumul >= line->dx)
		{
			line->cumul -= line->dx;
			line->y += line->yincr;
		}
		if ((line->x >= 0 && line->x <= WIDTH - 1) &&
			(line->y >= 1 && line->y <= HEIGHT - 1))
			draw_pixel(img, line->x, line->y, color);
		line->i++;
	}
}

int				draw_line(t_img *img, t_next *next, t_color *color)
{
	t_line	line;

	line.x = next->xsrc;
	line.y = next->ysrc;
	line.dx = next->xdest - next->xsrc;
	line.dy = next->ydest - next->ysrc;
	line.xincr = (line.dx > 0) ? 1 : -1;
	line.yincr = (line.dy > 0) ? 1 : -1;
	line.dx = abs(line.dx);
	line.dy = abs(line.dy);
	line.i = 0;
	if (line.dx > line.dy)
		dx_dy(img, color, &line);
	else
		dy_dx(img, color, &line);
	return (SUCCESS);
}
