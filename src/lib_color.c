/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:03:39 by lterrail          #+#    #+#             */
/*   Updated: 2018/10/23 18:13:46 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		blue1(t_color *color)
{
	color->r = 100;
	color->g = 149;
	color->b = 237;
}

void		yellow1(t_color *color)
{
	color->r = 255;
	color->g = 165;
	color->b = 79;
}

void		green1(t_color *color)
{
	color->r = 0;
	color->g = 205;
	color->b = 102;
}

void		green2(t_color *color)
{
	color->r = 0;
	color->g = 139;
	color->b = 69;
}

void		brawn1(t_color *color)
{
	color->r = 205;
	color->g = 133;
	color->b = 63;
}
