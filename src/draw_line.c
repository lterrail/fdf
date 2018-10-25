/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:07:59 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 21:15:58 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_pixel(t_img *img, int x, int y, t_color *color)
{
	img->data[(x * (img->bpp / 8)) + (y * img->size_line)] = color->b;
	img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 1] = color->g;
	img->data[(x * (img->bpp / 8)) + (y * img->size_line) + 2] = color->r;
}

static void		dy_dx(t_img *img, t_color *color, t_pt *pt)
{
	pt->cumul = 0;
	while (pt->i < pt->dy)
	{
		pt->y += pt->yincr;
		pt->cumul += pt->dx;
		if (pt->cumul >= pt->dy)
		{
			pt->cumul -= pt->dy;
			pt->x += pt->xincr;
		}
		if ((pt->x >= 0 && pt->x <= WIDTH - 1) &&
			(pt->y >= 1 && pt->y <= HEIGHT - 1))
			draw_pixel(img, pt->x, pt->y, color);
		pt->i++;
	}
}

static void		dx_dy(t_img *img, t_color *color, t_pt *pt)
{
	pt->cumul = 0;
	while (pt->i < pt->dx)
	{
		pt->x += pt->xincr;
		pt->cumul += pt->dy;
		if (pt->cumul >= pt->dx)
		{
			pt->cumul -= pt->dx;
			pt->y += pt->yincr;
		}
		if ((pt->x >= 0 && pt->x <= WIDTH - 1) &&
			(pt->y >= 1 && pt->y <= HEIGHT - 1))
			draw_pixel(img, pt->x, pt->y, color);
		pt->i++;
	}
}

int				draw_line(t_img *img, t_next *next, t_color *color)
{
	t_pt	pt;

	pt.x = next->xsrc;
	pt.y = next->ysrc;
	pt.dx = next->xdest - next->xsrc;
	pt.dy = next->ydest - next->ysrc;
	pt.xincr = (pt.dx > 0) ? 1 : -1;
	pt.yincr = (pt.dy > 0) ? 1 : -1;
	pt.dx = abs(pt.dx);
	pt.dy = abs(pt.dy);
	pt.i = 0;
	if (pt.dx > pt.dy)
		dx_dy(img, color, &pt);
	else
		dy_dx(img, color, &pt);
	return (SUCCESS);
}
