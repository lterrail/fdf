/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_color2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:03:28 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/25 15:06:12 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		brawn2(t_color *color)
{
	color->r = 139;
	color->g = 90;
	color->b = 43;
}

void		grey1(t_color *color)
{
	color->r = 192;
	color->g = 192;
	color->b = 192;
}

void		white(t_color *color)
{
	color->r = 255;
	color->g = 255;
	color->b = 255;
}

void		red1(t_color *color)
{
	color->r = 139;
	color->g = 0;
	color->b = 0;
}

void		blue2(t_color *color)
{
	color->r = 44;
	color->g = 117;
	color->b = 255;
}
